#pragma once
#include <windows.h>
#pragma comment(lib, "User32.lib")


#include "utilities/memory.h"
#include <iostream>
memory Memory{ "ac_client.exe" };
const auto module_baseaddress = Memory.get_modulebase_address("ac_client.exe");

constexpr auto local_player = 0x18AC00;
constexpr auto health = 0x0EC;
constexpr auto armor = 0x0F0;
constexpr auto ammo = 0x140;
constexpr auto killcount = 0x1DC;


const auto local_player_address = Memory.read<std::uintptr_t>(module_baseaddress + local_player);
const auto health_address = local_player_address + health;
const auto armor_address = local_player_address + armor;
const auto ammo_address = local_player_address + ammo;
const auto killcount_address = local_player_address + killcount;



namespace AssaultCube {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Main : public System::Windows::Forms::Form
	{
	public:
		Main(void)
		{
			
			InitializeComponent();
			
		}

	public:
		~Main()
		{
			if (components)
			{
				delete components;
			}
		}

	
	public: bool ArmorLoop = false;
	public: bool AmmoLoop = false;
	public: System::Windows::Forms::Panel^ panel1;
	public: System::Windows::Forms::Label^ Title;
	public: System::Windows::Forms::Panel^ BackgroundColor;

	public: System::Windows::Forms::Panel^ panel3;
	public: System::Windows::Forms::Button^ GiveArmor;

	public: System::Windows::Forms::Button^ GiveAmmo;

	public: System::Windows::Forms::Button^ GiveHealth;

	public:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
	
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Main::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->Title = (gcnew System::Windows::Forms::Label());
			this->BackgroundColor = (gcnew System::Windows::Forms::Panel());
			this->GiveArmor = (gcnew System::Windows::Forms::Button());
			this->GiveAmmo = (gcnew System::Windows::Forms::Button());
			this->GiveHealth = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->BackgroundColor->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->panel1->Controls->Add(this->Title);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(752, 79);
			this->panel1->TabIndex = 1;
			// 
			// Title
			// 
			this->Title->AutoSize = true;
			this->Title->Font = (gcnew System::Drawing::Font(L"Segoe UI", 30.75F, System::Drawing::FontStyle::Bold));
			this->Title->ForeColor = System::Drawing::Color::White;
			this->Title->Location = System::Drawing::Point(14, 10);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(413, 55);
			this->Title->TabIndex = 0;
			this->Title->Text = L"Assault Cube 1.3.0.2";
			this->Title->Click += gcnew System::EventHandler(this, &Main::label1_Click);
			// 
			// BackgroundColor
			// 
			this->BackgroundColor->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->BackgroundColor->Controls->Add(this->GiveArmor);
			this->BackgroundColor->Controls->Add(this->GiveAmmo);
			this->BackgroundColor->Controls->Add(this->GiveHealth);
			this->BackgroundColor->Location = System::Drawing::Point(12, 120);
			this->BackgroundColor->Name = L"BackgroundColor";
			this->BackgroundColor->Size = System::Drawing::Size(752, 296);
			this->BackgroundColor->TabIndex = 2;
			// 
			// GiveArmor
			// 
			this->GiveArmor->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(15)));
			this->GiveArmor->FlatAppearance->BorderSize = 0;
			this->GiveArmor->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->GiveArmor->Font = (gcnew System::Drawing::Font(L"Arial", 15, System::Drawing::FontStyle::Bold));
			this->GiveArmor->ForeColor = System::Drawing::Color::White;
			this->GiveArmor->Location = System::Drawing::Point(26, 195);
			this->GiveArmor->Name = L"GiveArmor";
			this->GiveArmor->Size = System::Drawing::Size(700, 49);
			this->GiveArmor->TabIndex = 5;
			this->GiveArmor->Text = L"Give Armor";
			this->GiveArmor->UseVisualStyleBackColor = false;
			this->GiveArmor->Click += gcnew System::EventHandler(this, &Main::GiveArmor_Click);
			// 
			// GiveAmmo
			// 
			this->GiveAmmo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(15)));
			this->GiveAmmo->FlatAppearance->BorderSize = 0;
			this->GiveAmmo->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->GiveAmmo->Font = (gcnew System::Drawing::Font(L"Arial", 15, System::Drawing::FontStyle::Bold));
			this->GiveAmmo->ForeColor = System::Drawing::Color::White;
			this->GiveAmmo->Location = System::Drawing::Point(26, 120);
			this->GiveAmmo->Name = L"GiveAmmo";
			this->GiveAmmo->Size = System::Drawing::Size(700, 49);
			this->GiveAmmo->TabIndex = 4;
			this->GiveAmmo->Text = L"Give Ammo";
			this->GiveAmmo->UseVisualStyleBackColor = false;
			this->GiveAmmo->Click += gcnew System::EventHandler(this, &Main::GiveAmmo_Click);
			// 
			// GiveHealth
			// 
			this->GiveHealth->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(15)));
			this->GiveHealth->FlatAppearance->BorderSize = 0;
			this->GiveHealth->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->GiveHealth->Font = (gcnew System::Drawing::Font(L"Arial", 15, System::Drawing::FontStyle::Bold));
			this->GiveHealth->ForeColor = System::Drawing::Color::White;
			this->GiveHealth->Location = System::Drawing::Point(26, 45);
			this->GiveHealth->Name = L"GiveHealth";
			this->GiveHealth->Size = System::Drawing::Size(700, 49);
			this->GiveHealth->TabIndex = 3;
			this->GiveHealth->Text = L"Give Health";
			this->GiveHealth->UseVisualStyleBackColor = false;
			this->GiveHealth->Click += gcnew System::EventHandler(this, &Main::GiveHealth_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::Red;
			this->panel3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->panel3->ForeColor = System::Drawing::Color::White;
			this->panel3->Location = System::Drawing::Point(12, 104);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(752, 1);
			this->panel3->TabIndex = 0;
			this->panel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Main::panel3_Paint);
			// 
			// Main
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)));
			this->ClientSize = System::Drawing::Size(776, 428);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->BackgroundColor);
			this->Controls->Add(this->panel1);
			this->ForeColor = System::Drawing::Color::Black;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Main";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Main";
			this->Load += gcnew System::EventHandler(this, &Main::Main_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->BackgroundColor->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		public: System::Void MoveMouseButton_Click(System::Object^ sender, System::EventArgs^ e) {
			POINT cursorPos;
			GetCursorPos(&cursorPos);

			int targetX = cursorPos.x + 100;
			int targetY = cursorPos.y + 100;

			// Smooth move function:
			const int steps = 50;
			int startX = cursorPos.x;
			int startY = cursorPos.y;

			for (int i = 1; i <= steps; i++) {
				int newX = startX + ((targetX - startX) * i) / steps;
				int newY = startY + ((targetY - startY) * i) / steps;

				SetCursorPos(newX, newY);
				Sleep(5); // small delay for smooth movement
			}
		}
	public: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	public: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
public: System::Void Main_Load(System::Object^ sender, System::EventArgs^ e) {
}

public: System::Void GiveHealth_Click(System::Object^ sender, System::EventArgs^ e) {
	Memory.write<int>(health_address, 9999);
}
public: System::Void GiveAmmo_Click(System::Object^ sender, System::EventArgs^ e) {
	Memory.write<int>(ammo_address, 9999);
}
public: System::Void panel3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	this->panel3->BackColor = System::Drawing::Color::Lime;
}

private: System::Void GiveArmor_Click(System::Object^ sender, System::EventArgs^ e) {
	Memory.write<int>(armor_address, 9999);
}

};

}

