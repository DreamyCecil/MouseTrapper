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

#pragma once

#include <windows.h>

namespace MouseTrapper {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainFrm
	/// </summary>
	public ref class MainFrm : public System::Windows::Forms::Form
	{
	public:
		MainFrm(void) {
			InitializeComponent();
		};

    // Get mouse limits
    bool GetLimits(RECT &rcClip);

	protected:
		~MainFrm() {
			if (components) {
				delete components;
			}
		};

  private: System::Windows::Forms::TextBox^  txtX1;
  private: System::Windows::Forms::TextBox^  txtY1;
  private: System::Windows::Forms::TextBox^  txtX2;
  private: System::Windows::Forms::TextBox^  txtY2;
  private: System::Windows::Forms::Label^  lblTopLeft;
  private: System::Windows::Forms::Label^  lblBottomRight;
  private: System::Windows::Forms::Button^  btnTrap;
  private: System::Windows::Forms::Label^  lblShortcut;
  private: System::Windows::Forms::Timer^  tmLoop;
  private: System::Windows::Forms::Label^  lblMouse;
  private: System::ComponentModel::IContainer^  components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
      this->components = (gcnew System::ComponentModel::Container());
      this->txtX1 = (gcnew System::Windows::Forms::TextBox());
      this->txtY1 = (gcnew System::Windows::Forms::TextBox());
      this->txtX2 = (gcnew System::Windows::Forms::TextBox());
      this->txtY2 = (gcnew System::Windows::Forms::TextBox());
      this->lblTopLeft = (gcnew System::Windows::Forms::Label());
      this->lblBottomRight = (gcnew System::Windows::Forms::Label());
      this->btnTrap = (gcnew System::Windows::Forms::Button());
      this->lblShortcut = (gcnew System::Windows::Forms::Label());
      this->tmLoop = (gcnew System::Windows::Forms::Timer(this->components));
      this->lblMouse = (gcnew System::Windows::Forms::Label());
      this->SuspendLayout();
      // 
      // txtX1
      // 
      this->txtX1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
      this->txtX1->Location = System::Drawing::Point(12, 33);
      this->txtX1->MaxLength = 10;
      this->txtX1->Name = L"txtX1";
      this->txtX1->Size = System::Drawing::Size(128, 29);
      this->txtX1->TabIndex = 0;
      this->txtX1->Text = L"0";
      // 
      // txtY1
      // 
      this->txtY1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
      this->txtY1->Location = System::Drawing::Point(12, 68);
      this->txtY1->MaxLength = 10;
      this->txtY1->Name = L"txtY1";
      this->txtY1->Size = System::Drawing::Size(128, 29);
      this->txtY1->TabIndex = 1;
      this->txtY1->Text = L"0";
      // 
      // txtX2
      // 
      this->txtX2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
      this->txtX2->Location = System::Drawing::Point(164, 33);
      this->txtX2->MaxLength = 10;
      this->txtX2->Name = L"txtX2";
      this->txtX2->Size = System::Drawing::Size(128, 29);
      this->txtX2->TabIndex = 2;
      this->txtX2->Text = L"640";
      // 
      // txtY2
      // 
      this->txtY2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
      this->txtY2->Location = System::Drawing::Point(164, 68);
      this->txtY2->MaxLength = 10;
      this->txtY2->Name = L"txtY2";
      this->txtY2->Size = System::Drawing::Size(128, 29);
      this->txtY2->TabIndex = 3;
      this->txtY2->Text = L"480";
      // 
      // lblTopLeft
      // 
      this->lblTopLeft->AutoSize = true;
      this->lblTopLeft->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
      this->lblTopLeft->Location = System::Drawing::Point(12, 9);
      this->lblTopLeft->Name = L"lblTopLeft";
      this->lblTopLeft->Size = System::Drawing::Size(66, 21);
      this->lblTopLeft->TabIndex = 1;
      this->lblTopLeft->Text = L"Top left";
      // 
      // lblBottomRight
      // 
      this->lblBottomRight->AutoSize = true;
      this->lblBottomRight->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
      this->lblBottomRight->Location = System::Drawing::Point(194, 9);
      this->lblBottomRight->Name = L"lblBottomRight";
      this->lblBottomRight->Size = System::Drawing::Size(105, 21);
      this->lblBottomRight->TabIndex = 1;
      this->lblBottomRight->Text = L"Bottom right";
      // 
      // btnTrap
      // 
      this->btnTrap->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
      this->btnTrap->Location = System::Drawing::Point(12, 181);
      this->btnTrap->Name = L"btnTrap";
      this->btnTrap->Size = System::Drawing::Size(280, 40);
      this->btnTrap->TabIndex = 4;
      this->btnTrap->Text = L"TRAP";
      this->btnTrap->UseVisualStyleBackColor = true;
      this->btnTrap->Click += gcnew System::EventHandler(this, &MainFrm::btnTrap_Click);
      // 
      // lblShortcut
      // 
      this->lblShortcut->AutoSize = true;
      this->lblShortcut->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
      this->lblShortcut->Location = System::Drawing::Point(82, 157);
      this->lblShortcut->Name = L"lblShortcut";
      this->lblShortcut->Size = System::Drawing::Size(138, 21);
      this->lblShortcut->TabIndex = 1;
      this->lblShortcut->Text = L"Shortcut: Ctrl+F11";
      this->lblShortcut->TextAlign = System::Drawing::ContentAlignment::TopCenter;
      // 
      // tmLoop
      // 
      this->tmLoop->Enabled = true;
      this->tmLoop->Interval = 10;
      this->tmLoop->Tick += gcnew System::EventHandler(this, &MainFrm::tmLoop_Tick);
      // 
      // lblMouse
      // 
      this->lblMouse->AutoSize = true;
      this->lblMouse->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
        static_cast<System::Byte>(204)));
      this->lblMouse->Location = System::Drawing::Point(8, 100);
      this->lblMouse->Name = L"lblMouse";
      this->lblMouse->Size = System::Drawing::Size(120, 21);
      this->lblMouse->TabIndex = 1;
      this->lblMouse->Text = L"Mouse position:";
      this->lblMouse->TextAlign = System::Drawing::ContentAlignment::TopCenter;
      // 
      // MainFrm
      // 
      this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
      this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
      this->ClientSize = System::Drawing::Size(304, 233);
      this->Controls->Add(this->btnTrap);
      this->Controls->Add(this->lblBottomRight);
      this->Controls->Add(this->lblMouse);
      this->Controls->Add(this->lblShortcut);
      this->Controls->Add(this->lblTopLeft);
      this->Controls->Add(this->txtY2);
      this->Controls->Add(this->txtY1);
      this->Controls->Add(this->txtX2);
      this->Controls->Add(this->txtX1);
      this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
      this->MaximizeBox = false;
      this->Name = L"MainFrm";
      this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
      this->Text = L"Mouse Trapper";
      this->ResumeLayout(false);
      this->PerformLayout();

    }
#pragma endregion

  Void btnTrap_Click(Object ^sender, EventArgs ^e);
  Void tmLoop_Tick(Object ^sender, EventArgs ^e);
};
}
