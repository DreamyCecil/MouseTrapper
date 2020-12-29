/* Copyright (c) 2020 Dreamy Cecil 
This program is free software; you can redistribute it and/or modify
it under the terms of version 2 of the GNU General Public License as published by
the Free Software Foundation


This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License along
with this program; if not, write to the Free Software Foundation, Inc.,
51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA. */

#include "MainFrm.h"
#include <sstream>

using namespace System;
using namespace System::Windows::Forms;

static bool _bTrapped = false;

// Hotkey
#define HOTKEY (GetKeyState(VK_CONTROL) & 0x8000) && (GetKeyState(VK_F11) & 0x8000)

static bool _bKeyPressed = false;
static bool _bKeyHolding = false;
static bool _bKeyReleased = false;

// Get limits for trapping
bool MouseTrapper::MainFrm::GetLimits(RECT &rcClip) {
  try {
    int iX1 = Int32::Parse(txtX1->Text);
    int iY1 = Int32::Parse(txtY1->Text);
    int iX2 = Int32::Parse(txtX2->Text);
    int iY2 = Int32::Parse(txtY2->Text);

    // Fix invalid horizontal limits
    if (iX1 >= iX2) {
      iX2 = iX1+1;

      std::ostringstream strPos;
      strPos << iX2;

      txtX2->Text = %String(strPos.str().c_str());
    }
    
    // Fix invalid vertical limits
    if (iY1 >= iY2) {
      iY2 = iY1+1;

      std::ostringstream strPos;
      strPos << iY2;

      txtY2->Text = %String(strPos.str().c_str());
    }

    rcClip.left = iX1;
    rcClip.top = iY1;
    rcClip.right = iX2;
    rcClip.bottom = iY2;

  } catch (FormatException ^) {
    MessageBox::Show("One of the limits doesn't contain a number!", "Incorrect limits", MessageBoxButtons::OK, MessageBoxIcon::Error);

    _bTrapped = false;
    return false;
  }

  return true;
};

// Trap or untrap
Void MouseTrapper::MainFrm::btnTrap_Click(Object ^sender, EventArgs ^e) {
  _bTrapped = !_bTrapped;
};

// Trapper loop
Void MouseTrapper::MainFrm::tmLoop_Tick(Object ^sender, EventArgs ^e) {
  _bKeyPressed = (HOTKEY && !_bKeyHolding);
  _bKeyReleased = (!HOTKEY && _bKeyHolding);

  _bKeyHolding = HOTKEY;

  if (_bKeyPressed) {
    btnTrap_Click(sender, e);
  }

  // Trap the mouse
  if (_bTrapped) {
    RECT rcClip;

    if (GetLimits(rcClip)) {
      btnTrap->Text = "UNTRAP";
      ClipCursor(&rcClip);
    }

  } else {
    btnTrap->Text = "TRAP";
    ClipCursor(NULL);
  }

  // Print mouse position
  POINT ptMouse;

  if (GetCursorPos(&ptMouse)) {
    std::ostringstream strMouse;
    strMouse << "Mouse position: " << ptMouse.x << ", " << ptMouse.y;

    lblMouse->Text = %String(strMouse.str().c_str());
  }
};

[STAThreadAttribute]
void Main(array<String ^> ^args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	MouseTrapper::MainFrm frm;
	Application::Run(%frm);
};