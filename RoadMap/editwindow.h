#include "creationwindow.h"
#pragma once

namespace RoadMap {

	using namespace System;
	using namespace System::Xml;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class editwindow : public System::Windows::Forms::Form
	{

		List<TextBox^>^ textBoxes = gcnew List<TextBox^>();

	public:


		editwindow(void)
		{
			InitializeComponent();
			draghandlers(light_bg);
			draghandlers(dark_bg);
		}

	protected:
		~editwindow()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::Windows::Forms::Label^ main_title;
		System::Windows::Forms::Label^ name_label;
		System::Windows::Forms::TextBox^ name_textbox;
		System::Windows::Forms::Label^ topic_label;
		System::Windows::Forms::Label^ subtopic_label;
		System::Windows::Forms::Button^ addnew_btn;
		System::Windows::Forms::Button^ save_btn;
		System::Windows::Forms::Label^ author_label;
		System::Windows::Forms::TextBox^ author_textbox;
		System::Windows::Forms::Label^ deadline_label;
		System::Windows::Forms::Button^ deletelast_btn;
		System::Windows::Forms::Panel^ light_bg;
		System::Windows::Forms::PictureBox^ logo;
		System::Windows::Forms::Panel^ dark_bg;
		System::Windows::Forms::Button^ close_btn;
		System::Windows::Forms::DateTimePicker^ deadline_textbox;
		System::Drawing::Point lastPoint;
		System::ComponentModel::Container^ components;
		System::Windows::Forms::Button^ upload_btn;
		System::Windows::Forms::Panel^ scroll_panel;
		System::Windows::Forms::TextBox^ description_textbox;
		System::Windows::Forms::TextBox^ topic_textbox;
		System::Windows::Forms::TextBox^ subtopic_textbox;


		int TopicCount = 0;
		bool dragging = false;


	protected:

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(editwindow::typeid));
			this->main_title = (gcnew System::Windows::Forms::Label());
			this->name_label = (gcnew System::Windows::Forms::Label());
			this->name_textbox = (gcnew System::Windows::Forms::TextBox());
			this->topic_label = (gcnew System::Windows::Forms::Label());
			this->subtopic_label = (gcnew System::Windows::Forms::Label());
			this->addnew_btn = (gcnew System::Windows::Forms::Button());
			this->save_btn = (gcnew System::Windows::Forms::Button());
			this->author_label = (gcnew System::Windows::Forms::Label());
			this->author_textbox = (gcnew System::Windows::Forms::TextBox());
			this->deadline_textbox = (gcnew System::Windows::Forms::DateTimePicker());
			this->deadline_label = (gcnew System::Windows::Forms::Label());
			this->deletelast_btn = (gcnew System::Windows::Forms::Button());
			this->light_bg = (gcnew System::Windows::Forms::Panel());
			this->scroll_panel = (gcnew System::Windows::Forms::Panel());
			this->description_textbox = (gcnew System::Windows::Forms::TextBox());
			this->topic_textbox = (gcnew System::Windows::Forms::TextBox());
			this->subtopic_textbox = (gcnew System::Windows::Forms::TextBox());
			this->close_btn = (gcnew System::Windows::Forms::Button());
			this->logo = (gcnew System::Windows::Forms::PictureBox());
			this->dark_bg = (gcnew System::Windows::Forms::Panel());
			this->upload_btn = (gcnew System::Windows::Forms::Button());
			this->light_bg->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logo))->BeginInit();
			this->dark_bg->SuspendLayout();
			this->SuspendLayout();
			// 
			// main_title
			// 
			this->main_title->AutoSize = true;
			this->main_title->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->main_title->Font = (gcnew System::Drawing::Font(L"Trebuchet MS", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->main_title->ForeColor = System::Drawing::Color::Black;
			this->main_title->Location = System::Drawing::Point(28, 25);
			this->main_title->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->main_title->Name = L"main_title";
			this->main_title->Size = System::Drawing::Size(0, 22);
			this->main_title->TabIndex = 0;
			// 
			// name_label
			// 
			this->name_label->AutoSize = true;
			this->name_label->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->name_label->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold));
			this->name_label->ForeColor = System::Drawing::Color::White;
			this->name_label->Location = System::Drawing::Point(50, 125);
			this->name_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->name_label->Name = L"name_label";
			this->name_label->Size = System::Drawing::Size(110, 15);
			this->name_label->TabIndex = 3;
			this->name_label->Text = L"ROADMAP NAME";
			// 
			// name_textbox
			// 
			this->name_textbox->BackColor = System::Drawing::Color::White;
			this->name_textbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->name_textbox->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Bold));
			this->name_textbox->ForeColor = System::Drawing::Color::Black;
			this->name_textbox->Location = System::Drawing::Point(50, 145);
			this->name_textbox->Margin = System::Windows::Forms::Padding(4);
			this->name_textbox->MaxLength = 45;
			this->name_textbox->Name = L"name_textbox";
			this->name_textbox->Size = System::Drawing::Size(200, 20);
			this->name_textbox->TabIndex = 6;
			// 
			// topic_label
			// 
			this->topic_label->AutoSize = true;
			this->topic_label->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->topic_label->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold));
			this->topic_label->ForeColor = System::Drawing::Color::White;
			this->topic_label->Location = System::Drawing::Point(50, 180);
			this->topic_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->topic_label->Name = L"topic_label";
			this->topic_label->Size = System::Drawing::Size(181, 15);
			this->topic_label->TabIndex = 7;
			this->topic_label->Text = L"TOPICS AND DESCRIPTIONS";
			// 
			// subtopic_label
			// 
			this->subtopic_label->AutoSize = true;
			this->subtopic_label->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->subtopic_label->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold));
			this->subtopic_label->ForeColor = System::Drawing::Color::White;
			this->subtopic_label->Location = System::Drawing::Point(300, 180);
			this->subtopic_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->subtopic_label->Name = L"subtopic_label";
			this->subtopic_label->Size = System::Drawing::Size(79, 15);
			this->subtopic_label->TabIndex = 8;
			this->subtopic_label->Text = L"SUBTOPICS";
			// 
			// addnew_btn
			// 
			this->addnew_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->addnew_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->addnew_btn->FlatAppearance->BorderSize = 0;
			this->addnew_btn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->addnew_btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->addnew_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->addnew_btn->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold));
			this->addnew_btn->ForeColor = System::Drawing::Color::White;
			this->addnew_btn->Location = System::Drawing::Point(50, 30);
			this->addnew_btn->Margin = System::Windows::Forms::Padding(4);
			this->addnew_btn->Name = L"addnew_btn";
			this->addnew_btn->Size = System::Drawing::Size(250, 40);
			this->addnew_btn->TabIndex = 13;
			this->addnew_btn->Text = L"ADD NEW ROW";
			this->addnew_btn->UseVisualStyleBackColor = false;
			this->addnew_btn->Visible = false;
			this->addnew_btn->Click += gcnew System::EventHandler(this, &editwindow::addnew_btn_Click);
			// 
			// save_btn
			// 
			this->save_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->save_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->save_btn->FlatAppearance->BorderSize = 0;
			this->save_btn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->save_btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->save_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->save_btn->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold));
			this->save_btn->ForeColor = System::Drawing::Color::White;
			this->save_btn->Location = System::Drawing::Point(650, 30);
			this->save_btn->Margin = System::Windows::Forms::Padding(4);
			this->save_btn->Name = L"save_btn";
			this->save_btn->Size = System::Drawing::Size(150, 40);
			this->save_btn->TabIndex = 14;
			this->save_btn->Text = L"SAVE";
			this->save_btn->UseVisualStyleBackColor = false;
			this->save_btn->Visible = false;
			this->save_btn->Click += gcnew System::EventHandler(this, &editwindow::save_btn_Click);
			// 
			// author_label
			// 
			this->author_label->AutoSize = true;
			this->author_label->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->author_label->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold));
			this->author_label->ForeColor = System::Drawing::Color::White;
			this->author_label->Location = System::Drawing::Point(300, 125);
			this->author_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->author_label->Name = L"author_label";
			this->author_label->Size = System::Drawing::Size(60, 15);
			this->author_label->TabIndex = 17;
			this->author_label->Text = L"AUTHOR";
			// 
			// author_textbox
			// 
			this->author_textbox->BackColor = System::Drawing::Color::White;
			this->author_textbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->author_textbox->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Bold));
			this->author_textbox->ForeColor = System::Drawing::Color::Black;
			this->author_textbox->Location = System::Drawing::Point(300, 145);
			this->author_textbox->Margin = System::Windows::Forms::Padding(4);
			this->author_textbox->MaxLength = 45;
			this->author_textbox->Name = L"author_textbox";
			this->author_textbox->Size = System::Drawing::Size(200, 20);
			this->author_textbox->TabIndex = 18;
			// 
			// deadline_textbox
			// 
			this->deadline_textbox->BackColor = System::Drawing::Color::Black;
			this->deadline_textbox->CalendarForeColor = System::Drawing::Color::White;
			this->deadline_textbox->CalendarMonthBackground = System::Drawing::Color::Black;
			this->deadline_textbox->CalendarTitleBackColor = System::Drawing::Color::Black;
			this->deadline_textbox->CalendarTitleForeColor = System::Drawing::Color::White;
			this->deadline_textbox->CalendarTrailingForeColor = System::Drawing::Color::Gray;
			this->deadline_textbox->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Bold));
			this->deadline_textbox->ForeColor = System::Drawing::Color::White;
			this->deadline_textbox->Location = System::Drawing::Point(550, 145);
			this->deadline_textbox->Margin = System::Windows::Forms::Padding(0);
			this->deadline_textbox->MinDate = System::DateTime(2024, 8, 20, 0, 0, 0, 0);
			this->deadline_textbox->Name = L"deadline_textbox";
			this->deadline_textbox->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->deadline_textbox->Size = System::Drawing::Size(250, 20);
			this->deadline_textbox->TabIndex = 19;
			// 
			// deadline_label
			// 
			this->deadline_label->AutoSize = true;
			this->deadline_label->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->deadline_label->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold));
			this->deadline_label->ForeColor = System::Drawing::Color::White;
			this->deadline_label->Location = System::Drawing::Point(550, 125);
			this->deadline_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->deadline_label->Name = L"deadline_label";
			this->deadline_label->Size = System::Drawing::Size(70, 15);
			this->deadline_label->TabIndex = 20;
			this->deadline_label->Text = L"DEADLINE";
			// 
			// deletelast_btn
			// 
			this->deletelast_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(69)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->deletelast_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->deletelast_btn->FlatAppearance->BorderSize = 0;
			this->deletelast_btn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(69)), static_cast<System::Int32>(static_cast<System::Byte>(69)));
			this->deletelast_btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->deletelast_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->deletelast_btn->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold));
			this->deletelast_btn->ForeColor = System::Drawing::Color::White;
			this->deletelast_btn->Location = System::Drawing::Point(310, 30);
			this->deletelast_btn->Margin = System::Windows::Forms::Padding(4);
			this->deletelast_btn->Name = L"deletelast_btn";
			this->deletelast_btn->Size = System::Drawing::Size(150, 40);
			this->deletelast_btn->TabIndex = 21;
			this->deletelast_btn->Text = L"DELETE LAST ROW";
			this->deletelast_btn->UseVisualStyleBackColor = false;
			this->deletelast_btn->Visible = false;
			this->deletelast_btn->Click += gcnew System::EventHandler(this, &editwindow::deletelast_btn_Click_1);
			// 
			// light_bg
			// 
			this->light_bg->BackColor = System::Drawing::Color::White;
			this->light_bg->Controls->Add(this->scroll_panel);
			this->light_bg->Controls->Add(this->description_textbox);
			this->light_bg->Controls->Add(this->topic_textbox);
			this->light_bg->Controls->Add(this->subtopic_textbox);
			this->light_bg->Controls->Add(this->name_label);
			this->light_bg->Controls->Add(this->close_btn);
			this->light_bg->Controls->Add(this->logo);
			this->light_bg->Controls->Add(this->author_label);
			this->light_bg->Controls->Add(this->subtopic_label);
			this->light_bg->Controls->Add(this->topic_label);
			this->light_bg->Controls->Add(this->name_textbox);
			this->light_bg->Controls->Add(this->deadline_textbox);
			this->light_bg->Controls->Add(this->author_textbox);
			this->light_bg->Controls->Add(this->deadline_label);
			this->light_bg->Dock = System::Windows::Forms::DockStyle::Top;
			this->light_bg->Location = System::Drawing::Point(0, 0);
			this->light_bg->Name = L"light_bg";
			this->light_bg->Size = System::Drawing::Size(850, 650);
			this->light_bg->TabIndex = 24;
			// 
			// scroll_panel
			// 
			this->scroll_panel->AutoScroll = true;
			this->scroll_panel->BackColor = System::Drawing::Color::White;
			this->scroll_panel->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Bold));
			this->scroll_panel->Location = System::Drawing::Point(50, 277);
			this->scroll_panel->Name = L"scroll_panel";
			this->scroll_panel->Size = System::Drawing::Size(775, 370);
			this->scroll_panel->TabIndex = 26;
			// 
			// description_textbox
			// 
			this->description_textbox->BackColor = System::Drawing::Color::White;
			this->description_textbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->description_textbox->Enabled = false;
			this->description_textbox->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Bold));
			this->description_textbox->ForeColor = System::Drawing::Color::Black;
			this->description_textbox->Location = System::Drawing::Point(50, 230);
			this->description_textbox->Margin = System::Windows::Forms::Padding(4);
			this->description_textbox->MaxLength = 150;
			this->description_textbox->Multiline = true;
			this->description_textbox->Name = L"description_textbox";
			this->description_textbox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->description_textbox->Size = System::Drawing::Size(200, 40);
			this->description_textbox->TabIndex = 27;
			this->description_textbox->Text = L"#Enter description for topic";
			// 
			// topic_textbox
			// 
			this->topic_textbox->BackColor = System::Drawing::Color::White;
			this->topic_textbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->topic_textbox->Enabled = false;
			this->topic_textbox->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->topic_textbox->ForeColor = System::Drawing::Color::Black;
			this->topic_textbox->Location = System::Drawing::Point(50, 200);
			this->topic_textbox->Margin = System::Windows::Forms::Padding(4);
			this->topic_textbox->MaxLength = 45;
			this->topic_textbox->Name = L"topic_textbox";
			this->topic_textbox->Size = System::Drawing::Size(200, 20);
			this->topic_textbox->TabIndex = 24;
			this->topic_textbox->Text = L"#Enter topicname";
			// 
			// subtopic_textbox
			// 
			this->subtopic_textbox->BackColor = System::Drawing::Color::White;
			this->subtopic_textbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->subtopic_textbox->Enabled = false;
			this->subtopic_textbox->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Bold));
			this->subtopic_textbox->ForeColor = System::Drawing::Color::Black;
			this->subtopic_textbox->Location = System::Drawing::Point(300, 200);
			this->subtopic_textbox->Margin = System::Windows::Forms::Padding(4);
			this->subtopic_textbox->MaxLength = 1000;
			this->subtopic_textbox->Multiline = true;
			this->subtopic_textbox->Name = L"subtopic_textbox";
			this->subtopic_textbox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->subtopic_textbox->Size = System::Drawing::Size(500, 70);
			this->subtopic_textbox->TabIndex = 25;
			this->subtopic_textbox->Text = L"#Enter subtopics names. Use \",\" (commas) to separate suptopics.\r\n";
			// 
			// close_btn
			// 
			this->close_btn->BackColor = System::Drawing::Color::White;
			this->close_btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"close_btn.BackgroundImage")));
			this->close_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->close_btn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(21)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(26)));
			this->close_btn->FlatAppearance->BorderSize = 0;
			this->close_btn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(21)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(26)));
			this->close_btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(21)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(26)));
			this->close_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->close_btn->Location = System::Drawing::Point(815, 15);
			this->close_btn->Margin = System::Windows::Forms::Padding(0);
			this->close_btn->Name = L"close_btn";
			this->close_btn->Size = System::Drawing::Size(20, 20);
			this->close_btn->TabIndex = 4;
			this->close_btn->UseVisualStyleBackColor = false;
			this->close_btn->Click += gcnew System::EventHandler(this, &editwindow::close_btn_Click);
			// 
			// logo
			// 
			this->logo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logo.Image")));
			this->logo->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->logo->Location = System::Drawing::Point(50, 50);
			this->logo->Name = L"logo";
			this->logo->Size = System::Drawing::Size(130, 35);
			this->logo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->logo->TabIndex = 0;
			this->logo->TabStop = false;
			// 
			// dark_bg
			// 
			this->dark_bg->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(21)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(26)));
			this->dark_bg->Controls->Add(this->upload_btn);
			this->dark_bg->Controls->Add(this->save_btn);
			this->dark_bg->Controls->Add(this->addnew_btn);
			this->dark_bg->Controls->Add(this->deletelast_btn);
			this->dark_bg->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->dark_bg->Location = System::Drawing::Point(0, 650);
			this->dark_bg->Name = L"dark_bg";
			this->dark_bg->Size = System::Drawing::Size(850, 100);
			this->dark_bg->TabIndex = 25;
			// 
			// upload_btn
			// 
			this->upload_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->upload_btn->Cursor = System::Windows::Forms::Cursors::Hand;
			this->upload_btn->FlatAppearance->BorderSize = 0;
			this->upload_btn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)),
				static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
			this->upload_btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->upload_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->upload_btn->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold));
			this->upload_btn->ForeColor = System::Drawing::Color::White;
			this->upload_btn->Location = System::Drawing::Point(490, 30);
			this->upload_btn->Margin = System::Windows::Forms::Padding(4);
			this->upload_btn->Name = L"upload_btn";
			this->upload_btn->Size = System::Drawing::Size(150, 40);
			this->upload_btn->TabIndex = 22;
			this->upload_btn->Text = L"UPLOAD";
			this->upload_btn->UseVisualStyleBackColor = false;
			this->upload_btn->Click += gcnew System::EventHandler(this, &editwindow::upload_btn_Click);
			// 
			// editwindow
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(248)),
				static_cast<System::Int32>(static_cast<System::Byte>(249)));
			this->ClientSize = System::Drawing::Size(850, 750);
			this->Controls->Add(this->light_bg);
			this->Controls->Add(this->main_title);
			this->Controls->Add(this->dark_bg);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"editwindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"RoadMap - Edit existing RoadMap";
			this->light_bg->ResumeLayout(false);
			this->light_bg->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logo))->EndInit();
			this->dark_bg->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private:

		// Drag window

		void draghandlers(System::Windows::Forms::Panel^ panel) {
			panel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &editwindow::window_mousedown);
			panel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &editwindow::window_mousemove);
			panel->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &editwindow::window_mouseup);
		}

		void window_mousedown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			if (e->Button == System::Windows::Forms::MouseButtons::Left)
			{
				dragging = true;
				lastPoint = e->Location;
			}
		}

		void window_mousemove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			if (dragging)
			{
				this->Location = System::Drawing::Point(this->Location.X + (e->Location.X - lastPoint.X), this->Location.Y + (e->Location.Y - lastPoint.Y));
			}
		}

		void window_mouseup(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			dragging = false;
		}

		// Close button

		System::Void close_btn_Click(System::Object^ sender, System::EventArgs^ e) {
			System::Windows::Forms::DialogResult result = MessageBox::Show(
				"Are you sure you want to close this window? Unsaved information will be deleted.",
				"Confirmation",
				MessageBoxButtons::YesNo,
				MessageBoxIcon::Question);

			if (result == System::Windows::Forms::DialogResult::Yes) {
				this->Close();
			}
		}

		// Add new row button

		System::Void addnew_btn_Click(System::Object^ sender, System::EventArgs^ e) {
			if (TopicCount >= 15) {
				MessageBox::Show("Maximum 15 Topics allowed.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			TextBox^ newtopic_textbox = gcnew TextBox();
			TextBox^ newsubtopic_textbox = gcnew TextBox();
			TextBox^ newdescription_textbox = gcnew TextBox();

			int verticalSpacing = 60;

			int newY;

			if (TopicCount == 0) {
				newY = topic_textbox->Location.Y + topic_textbox->Height + verticalSpacing;
				newtopic_textbox->Location = System::Drawing::Point(topic_textbox->Location.X - scroll_panel->Location.X, newY - scroll_panel->Location.Y);
				newtopic_textbox->Size = topic_textbox->Size;

				newsubtopic_textbox->Location = System::Drawing::Point(subtopic_textbox->Location.X - scroll_panel->Location.X, newY - scroll_panel->Location.Y);
				newsubtopic_textbox->Size = subtopic_textbox->Size;

				newdescription_textbox->Location = System::Drawing::Point(description_textbox->Location.X - scroll_panel->Location.X, newY + 27 - scroll_panel->Location.Y);
				newdescription_textbox->Size = description_textbox->Size;
			}
			else {
				TextBox^ lasttopic_textbox = (TextBox^)textBoxes[textBoxes->Count - 3];
				newY = lasttopic_textbox->Location.Y + lasttopic_textbox->Height + verticalSpacing;

				newtopic_textbox->Location = System::Drawing::Point(lasttopic_textbox->Location.X, newY);
				newtopic_textbox->Size = lasttopic_textbox->Size;

				TextBox^ lastsubtopic_textbox = (TextBox^)textBoxes[textBoxes->Count - 2];
				newsubtopic_textbox->Location = System::Drawing::Point(lastsubtopic_textbox->Location.X, newY);
				newsubtopic_textbox->Size = lastsubtopic_textbox->Size;

				TextBox^ lastdescription_textbox = (TextBox^)textBoxes[textBoxes->Count - 1];
				newdescription_textbox->Location = System::Drawing::Point(lastdescription_textbox->Location.X, newY + 27);
				newdescription_textbox->Size = lastdescription_textbox->Size;
			}

			newtopic_textbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			newsubtopic_textbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			newdescription_textbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;

			newtopic_textbox->Name = "topic_textbox_" + TopicCount.ToString();
			newsubtopic_textbox->Name = "subtopic_textbox_" + TopicCount.ToString();
			newdescription_textbox->Name = "description_textbox_" + TopicCount.ToString();

			newtopic_textbox->MaxLength = 45;
			newsubtopic_textbox->MaxLength = 1500;
			newdescription_textbox->MaxLength = 150;

			newsubtopic_textbox->Multiline = true;
			newsubtopic_textbox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;

			newdescription_textbox->Multiline = true;
			newdescription_textbox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;

			this->scroll_panel->Controls->Add(newtopic_textbox);
			this->scroll_panel->Controls->Add(newsubtopic_textbox);
			this->scroll_panel->Controls->Add(newdescription_textbox);

			textBoxes->Add(newtopic_textbox);
			textBoxes->Add(newsubtopic_textbox);
			textBoxes->Add(newdescription_textbox);

			TopicCount++;
		}

		// Save button

		System::Void save_btn_Click(System::Object^ sender, System::EventArgs^ e) {
			if (name_textbox->Text->Length > 40 || name_textbox->Text->Length == 0) {
				MessageBox::Show("Error occurred while saving the Roadmap: Roadmap name can be up to 40 characters long and cannot be empty.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			if (author_textbox->Text->Length > 45 || author_textbox->Text->Length == 0) {
				MessageBox::Show("Error occurred while saving the Roadmap: Author name can be up to 45 characters long and cannot be empty.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			for (int i = 0; i < textBoxes->Count; i += 3) {
				String^ subtopicText = textBoxes[i + 1]->Text->Trim();
				String^ descriptionText = textBoxes[i + 2]->Text->Trim();

				int subtopicCount = subtopicText->Split(gcnew array<wchar_t>{','}, StringSplitOptions::RemoveEmptyEntries)->Length;

				if (descriptionText->Length > 0 && subtopicCount < 4) {
					MessageBox::Show("Error occurred while saving the Roadmap: Each row must have at least 4 subtopics if a description is provided. Please add more subtopics before saving.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
				String^ TopicText = textBoxes[i]->Text->Trim();
				if (TopicText->Length > 40 || TopicText->Length == 0) {
					MessageBox::Show("Error occurred while saving the Roadmap: Topic name can be up to 40 characters long and cannot be empty (Row number: " + (i / 3 + 1).ToString() + ").", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
				if (descriptionText->Length > 150) {
					MessageBox::Show("Error occurred while saving the Roadmap: Description can be up to 150 characters long (Row number: " + (i / 3 + 1).ToString() + ").", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
				if (String::IsNullOrWhiteSpace(subtopicText)) {
					MessageBox::Show("Error occurred while saving the Roadmap: Subtopic cannot be empty (Row number: " + (i / 3 + 1).ToString() + ").", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
				int commaIndex = subtopicText->IndexOf(",");
				if (commaIndex >= 0) {
					if (commaIndex > 45) {
						MessageBox::Show("Error occurred while saving the Roadmap: You can enter only 45 symbols before comma in subtopics (Row number: " + (i / 3 + 1).ToString() + ").", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
						return;
					}
				}
				else {
					if (subtopicText->Length > 45) {
						MessageBox::Show("Error occurred while saving the Roadmap: You can enter only 45 symbols before comma in subtopics (Row number: " + (i / 3 + 1).ToString() + ").", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
						return;
					}
				}
			}

			System::Xml::XmlDocument^ xmlDoc = gcnew System::Xml::XmlDocument();
			System::Xml::XmlElement^ rootNode = xmlDoc->CreateElement("RoadMap");

			System::Xml::XmlElement^ infoNode = xmlDoc->CreateElement("MAPINFO");
			infoNode->SetAttribute("Title", name_textbox->Text);
			infoNode->SetAttribute("Author", author_textbox->Text);
			rootNode->AppendChild(infoNode);

			for (int i = 0; i < textBoxes->Count; i += 3) {
				String^ TopicText = textBoxes[i]->Text->Trim();
				String^ DescriptionText = textBoxes[i + 2]->Text->Trim();
				String^ SubtopicTextDynamic = textBoxes[i + 1]->Text->Trim();

				SubtopicTextDynamic = SubtopicTextDynamic->Replace("\r", "")->Replace("\n", "");

				System::Xml::XmlElement^ rowsNode = xmlDoc->CreateElement("ROWS");
				rowsNode->SetAttribute("Topic", TopicText);
				rowsNode->SetAttribute("Description", DescriptionText);
				rowsNode->SetAttribute("Subtopic", SubtopicTextDynamic);
				rootNode->AppendChild(rowsNode);
			}

			System::Xml::XmlElement^ dateNode = xmlDoc->CreateElement("DATE");
			dateNode->SetAttribute("Deadline", deadline_textbox->Value.ToString("yyyy-MM-dd"));
			rootNode->AppendChild(dateNode);

			xmlDoc->AppendChild(rootNode);

			try {
				SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog();
				saveFileDialog1->Filter = "XML files (*.xml)|*.xml";
				saveFileDialog1->FilterIndex = 1;
				saveFileDialog1->RestoreDirectory = true;

				if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
					String^ filePath = saveFileDialog1->FileName;
					xmlDoc->Save(filePath);
					MessageBox::Show("Roadmap saved successfully. \n\nPlease, go back to the start window and choose 'UPLOAD EXISTING ROADMAP'.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
			}
			catch (Exception^ ex) {
				MessageBox::Show("Error occurred while saving the Roadmap: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		// Delete last row button

		System::Void deletelast_btn_Click_1(System::Object^ sender, System::EventArgs^ e) {
			if (textBoxes->Count > 3) {
				System::Windows::Forms::DialogResult result = MessageBox::Show(
					"Are you sure you want to delete the last row?",
					"Confirmation",
					MessageBoxButtons::YesNo,
					MessageBoxIcon::Question);

				if (result == System::Windows::Forms::DialogResult::Yes) {
					TextBox^ lastdescription_textbox = safe_cast<TextBox^>(textBoxes[textBoxes->Count - 1]);
					TextBox^ lastsubtopic_textbox = safe_cast<TextBox^>(textBoxes[textBoxes->Count - 2]);
					TextBox^ lasttopic_textbox = safe_cast<TextBox^>(textBoxes[textBoxes->Count - 3]);

					this->scroll_panel->Controls->Remove(lastdescription_textbox);
					this->scroll_panel->Controls->Remove(lastsubtopic_textbox);
					this->scroll_panel->Controls->Remove(lasttopic_textbox);

					textBoxes->RemoveAt(textBoxes->Count - 1);
					textBoxes->RemoveAt(textBoxes->Count - 1);
					textBoxes->RemoveAt(textBoxes->Count - 1);

					int newHeight = (textBoxes->Count > 0) ? textBoxes[textBoxes->Count - 1]->Location.Y + textBoxes[textBoxes->Count - 1]->Height + 50 : 0;
					this->scroll_panel->AutoScrollMinSize = System::Drawing::Size(this->scroll_panel->ClientSize.Width, newHeight);

					TopicCount--;
				}
			}
			else {
				MessageBox::Show("Error occurred while deliting row: At least one row must remain.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}

		// Upload button

		System::Void upload_btn_Click(System::Object^ sender, System::EventArgs^ e) {
			OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog();
			openFileDialog1->Filter = "XML files (*.xml)|*.xml";
			openFileDialog1->FilterIndex = 1;
			openFileDialog1->RestoreDirectory = true;

			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				String^ filePath = openFileDialog1->FileName;
				System::Xml::XmlDocument^ xmlDoc = gcnew System::Xml::XmlDocument();

				try {
					xmlDoc->Load(filePath);

					System::Xml::XmlNode^ mapInfoNode = xmlDoc->SelectSingleNode("//MAPINFO");
					if (mapInfoNode != nullptr) {
						name_textbox->Text = mapInfoNode->Attributes["Title"]->Value;
						author_textbox->Text = mapInfoNode->Attributes["Author"]->Value;
					}

					System::Xml::XmlNode^ dateNode = xmlDoc->SelectSingleNode("//DATE");
					if (dateNode != nullptr) {
						String^ deadlineStr = dateNode->Attributes["Deadline"]->Value;
						DateTime deadlineDate;
						if (DateTime::TryParse(deadlineStr, deadlineDate)) {
							deadline_textbox->Value = deadlineDate;
						}
						else {
							MessageBox::Show("Error occurred while uploading the Roadmap: Invalid date format in XML file.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
						}
					}

					this->textBoxes->Clear();
					this->scroll_panel->Controls->Clear();
					TopicCount = 0;

					System::Xml::XmlNodeList^ rowsNodes = xmlDoc->GetElementsByTagName("ROWS");

					for (int i = 0; i < rowsNodes->Count; i++) {
						System::Xml::XmlElement^ rowElement = safe_cast<System::Xml::XmlElement^>(rowsNodes[i]);
						String^ topic = rowElement->GetAttribute("Topic");
						String^ subtopic = rowElement->GetAttribute("Subtopic");
						String^ description = rowElement->GetAttribute("Description");

						addnew_btn_Click(nullptr, nullptr);

						TextBox^ lasttopic_textbox = safe_cast<TextBox^>(textBoxes[textBoxes->Count - 3]);
						TextBox^ lastsubtopic_textbox = safe_cast<TextBox^>(textBoxes[textBoxes->Count - 2]);
						TextBox^ lastdescription_textbox = safe_cast<TextBox^>(textBoxes[textBoxes->Count - 1]);

						lasttopic_textbox->Text = topic;
						lastsubtopic_textbox->Text = subtopic;
						lastdescription_textbox->Text = description;
					}

					addnew_btn->Visible = true;
					deletelast_btn->Visible = true;
					save_btn->Visible = true;

					MessageBox::Show("Data loaded successfully.", "Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
				}
				catch (Exception^ ex) {
					MessageBox::Show("Error occurred while loading file: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}
			}
		}
	};
}