#pragma once

#include <msclr/marshal_cppstd.h>
#include <fstream>
#include <string>

namespace RoadMap {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Xml;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class mapwindow : public System::Windows::Forms::Form {

    public:
        mapwindow(void) {
            InitializeComponent();
            draghandlers(light_bg);
            draghandlers(dark_bg);
        }

    protected:
        ~mapwindow() {
            if (components) {
                delete components;
            }
        }

    private:
        System::Windows::Forms::OpenFileDialog^ openFileDialog1;
        System::Windows::Forms::Label^ topics_label;
        System::Windows::Forms::Label^ subtopics_label;
        System::Windows::Forms::Label^ name_label;
        System::Windows::Forms::Label^ author_label;
        System::Windows::Forms::Label^ deadline_label;
        System::Windows::Forms::Label^ progress_label;
        System::Windows::Forms::TextBox^ author_textbox;
        System::Windows::Forms::Panel^ scroll_panel;
        System::Windows::Forms::Panel^ dark_bg;
        System::Windows::Forms::Panel^ light_bg;
        System::Windows::Forms::TextBox^ deadline_textbox;
        System::Windows::Forms::PictureBox^ logo;
        System::Windows::Forms::Button^ upload_btn;
        System::Windows::Forms::Button^ save_btn;
        System::Windows::Forms::Button^ close_btn;
        System::ComponentModel::Container^ components;
        System::Drawing::Point lastPoint;


        bool dragging = false;


#pragma region Windows Form Designer generated code

           void InitializeComponent(void) {
               System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(mapwindow::typeid));
               this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
               this->topics_label = (gcnew System::Windows::Forms::Label());
               this->subtopics_label = (gcnew System::Windows::Forms::Label());
               this->name_label = (gcnew System::Windows::Forms::Label());
               this->author_label = (gcnew System::Windows::Forms::Label());
               this->deadline_label = (gcnew System::Windows::Forms::Label());
               this->progress_label = (gcnew System::Windows::Forms::Label());
               this->author_textbox = (gcnew System::Windows::Forms::TextBox());
               this->scroll_panel = (gcnew System::Windows::Forms::Panel());
               this->dark_bg = (gcnew System::Windows::Forms::Panel());
               this->close_btn = (gcnew System::Windows::Forms::Button());
               this->upload_btn = (gcnew System::Windows::Forms::Button());
               this->save_btn = (gcnew System::Windows::Forms::Button());
               this->light_bg = (gcnew System::Windows::Forms::Panel());
               this->deadline_textbox = (gcnew System::Windows::Forms::TextBox());
               this->logo = (gcnew System::Windows::Forms::PictureBox());
               this->dark_bg->SuspendLayout();
               this->light_bg->SuspendLayout();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logo))->BeginInit();
               this->SuspendLayout();
               // 
               // topics_label
               // 
               this->topics_label->AutoSize = true;
               this->topics_label->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
                   static_cast<System::Int32>(static_cast<System::Byte>(45)));
               this->topics_label->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold));
               this->topics_label->ForeColor = System::Drawing::Color::White;
               this->topics_label->Location = System::Drawing::Point(50, 180);
               this->topics_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
               this->topics_label->Name = L"topics_label";
               this->topics_label->Size = System::Drawing::Size(173, 15);
               this->topics_label->TabIndex = 10;
               this->topics_label->Text = L"TOPICS AND DESCRIPTION";
               // 
               // subtopics_label
               // 
               this->subtopics_label->AutoSize = true;
               this->subtopics_label->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
                   static_cast<System::Int32>(static_cast<System::Byte>(45)));
               this->subtopics_label->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold));
               this->subtopics_label->ForeColor = System::Drawing::Color::White;
               this->subtopics_label->Location = System::Drawing::Point(300, 180);
               this->subtopics_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
               this->subtopics_label->Name = L"subtopics_label";
               this->subtopics_label->Size = System::Drawing::Size(79, 15);
               this->subtopics_label->TabIndex = 11;
               this->subtopics_label->Text = L"SUBTOPICS";
               // 
               // name_label
               // 
               this->name_label->AutoSize = true;
               this->name_label->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(34)), static_cast<System::Int32>(static_cast<System::Byte>(96)),
                   static_cast<System::Int32>(static_cast<System::Byte>(255)));
               this->name_label->Font = (gcnew System::Drawing::Font(L"Arial Black", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->name_label->ForeColor = System::Drawing::Color::White;
               this->name_label->Location = System::Drawing::Point(230, 50);
               this->name_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
               this->name_label->Name = L"name_label";
               this->name_label->Size = System::Drawing::Size(52, 30);
               this->name_label->TabIndex = 12;
               this->name_label->Text = L"\?\?\?";
               // 
               // author_label
               // 
               this->author_label->AutoSize = true;
               this->author_label->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
                   static_cast<System::Int32>(static_cast<System::Byte>(45)));
               this->author_label->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
               this->author_label->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold));
               this->author_label->ForeColor = System::Drawing::Color::White;
               this->author_label->Location = System::Drawing::Point(50, 125);
               this->author_label->Name = L"author_label";
               this->author_label->Size = System::Drawing::Size(60, 15);
               this->author_label->TabIndex = 21;
               this->author_label->Text = L"AUTHOR";
               // 
               // deadline_label
               // 
               this->deadline_label->AutoSize = true;
               this->deadline_label->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
                   static_cast<System::Int32>(static_cast<System::Byte>(45)));
               this->deadline_label->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold));
               this->deadline_label->ForeColor = System::Drawing::Color::White;
               this->deadline_label->Location = System::Drawing::Point(300, 125);
               this->deadline_label->Name = L"deadline_label";
               this->deadline_label->Size = System::Drawing::Size(70, 15);
               this->deadline_label->TabIndex = 22;
               this->deadline_label->Text = L"DEADLINE";
               // 
               // progress_label
               // 
               this->progress_label->AutoSize = true;
               this->progress_label->BackColor = System::Drawing::Color::White;
               this->progress_label->Font = (gcnew System::Drawing::Font(L"Arial Black", 8.25F, System::Drawing::FontStyle::Bold));
               this->progress_label->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
                   static_cast<System::Int32>(static_cast<System::Byte>(45)));
               this->progress_label->Location = System::Drawing::Point(229, 80);
               this->progress_label->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
               this->progress_label->Name = L"progress_label";
               this->progress_label->Size = System::Drawing::Size(141, 15);
               this->progress_label->TabIndex = 24;
               this->progress_label->Text = L"Progress: 0 / 0 (0,00%)";
               // 
               // author_textbox
               // 
               this->author_textbox->BackColor = System::Drawing::Color::White;
               this->author_textbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
               this->author_textbox->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Bold));
               this->author_textbox->Location = System::Drawing::Point(50, 145);
               this->author_textbox->Name = L"author_textbox";
               this->author_textbox->ReadOnly = true;
               this->author_textbox->Size = System::Drawing::Size(200, 20);
               this->author_textbox->TabIndex = 25;
               // 
               // scroll_panel
               // 
               this->scroll_panel->BackColor = System::Drawing::Color::White;
               this->scroll_panel->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Bold));
               this->scroll_panel->Location = System::Drawing::Point(50, 200);
               this->scroll_panel->Margin = System::Windows::Forms::Padding(4);
               this->scroll_panel->Name = L"scroll_panel";
               this->scroll_panel->Size = System::Drawing::Size(750, 538);
               this->scroll_panel->TabIndex = 8;
               // 
               // dark_bg
               // 
               this->dark_bg->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(21)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
                   static_cast<System::Int32>(static_cast<System::Byte>(26)));
               this->dark_bg->Controls->Add(this->close_btn);
               this->dark_bg->Controls->Add(this->upload_btn);
               this->dark_bg->Controls->Add(this->save_btn);
               this->dark_bg->Dock = System::Windows::Forms::DockStyle::Right;
               this->dark_bg->Location = System::Drawing::Point(800, 0);
               this->dark_bg->Name = L"dark_bg";
               this->dark_bg->Size = System::Drawing::Size(200, 750);
               this->dark_bg->TabIndex = 27;
               // 
               // close_btn
               // 
               this->close_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(21)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
                   static_cast<System::Int32>(static_cast<System::Byte>(30)));
               this->close_btn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"close_btn.BackgroundImage")));
               this->close_btn->Cursor = System::Windows::Forms::Cursors::Hand;
               this->close_btn->FlatAppearance->BorderColor = System::Drawing::Color::White;
               this->close_btn->FlatAppearance->BorderSize = 0;
               this->close_btn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
               this->close_btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
               this->close_btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
               this->close_btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(21)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
                   static_cast<System::Int32>(static_cast<System::Byte>(26)));
               this->close_btn->Location = System::Drawing::Point(165, 15);
               this->close_btn->Name = L"close_btn";
               this->close_btn->Size = System::Drawing::Size(20, 20);
               this->close_btn->TabIndex = 4;
               this->close_btn->UseVisualStyleBackColor = false;
               this->close_btn->Click += gcnew System::EventHandler(this, &mapwindow::close_btn_Click);
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
               this->upload_btn->Location = System::Drawing::Point(20, 620);
               this->upload_btn->Margin = System::Windows::Forms::Padding(4);
               this->upload_btn->Name = L"upload_btn";
               this->upload_btn->Size = System::Drawing::Size(160, 43);
               this->upload_btn->TabIndex = 16;
               this->upload_btn->Text = L"UPLOAD";
               this->upload_btn->UseVisualStyleBackColor = false;
               this->upload_btn->Click += gcnew System::EventHandler(this, &mapwindow::uploadButton_Click);
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
               this->save_btn->Location = System::Drawing::Point(20, 680);
               this->save_btn->Margin = System::Windows::Forms::Padding(4);
               this->save_btn->Name = L"save_btn";
               this->save_btn->Size = System::Drawing::Size(160, 43);
               this->save_btn->TabIndex = 15;
               this->save_btn->Text = L"SAVE CHANGES";
               this->save_btn->UseVisualStyleBackColor = false;
               this->save_btn->Click += gcnew System::EventHandler(this, &mapwindow::saveButton_Click);
               // 
               // light_bg
               // 
               this->light_bg->BackColor = System::Drawing::Color::White;
               this->light_bg->Controls->Add(this->deadline_textbox);
               this->light_bg->Controls->Add(this->logo);
               this->light_bg->Controls->Add(this->deadline_label);
               this->light_bg->Controls->Add(this->name_label);
               this->light_bg->Controls->Add(this->progress_label);
               this->light_bg->Controls->Add(this->subtopics_label);
               this->light_bg->Dock = System::Windows::Forms::DockStyle::Left;
               this->light_bg->Location = System::Drawing::Point(0, 0);
               this->light_bg->Name = L"light_bg";
               this->light_bg->Size = System::Drawing::Size(800, 750);
               this->light_bg->TabIndex = 28;
               // 
               // deadline_textbox
               // 
               this->deadline_textbox->BackColor = System::Drawing::Color::White;
               this->deadline_textbox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
               this->deadline_textbox->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Bold));
               this->deadline_textbox->Location = System::Drawing::Point(300, 145);
               this->deadline_textbox->Name = L"deadline_textbox";
               this->deadline_textbox->ReadOnly = true;
               this->deadline_textbox->Size = System::Drawing::Size(200, 20);
               this->deadline_textbox->TabIndex = 26;
               // 
               // logo
               // 
               this->logo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"logo.Image")));
               this->logo->ImeMode = System::Windows::Forms::ImeMode::NoControl;
               this->logo->Location = System::Drawing::Point(50, 50);
               this->logo->Name = L"logo";
               this->logo->Size = System::Drawing::Size(130, 35);
               this->logo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
               this->logo->TabIndex = 1;
               this->logo->TabStop = false;
               // 
               // mapwindow
               // 
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
               this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(244)), static_cast<System::Int32>(static_cast<System::Byte>(248)),
                   static_cast<System::Int32>(static_cast<System::Byte>(249)));
               this->ClientSize = System::Drawing::Size(1000, 750);
               this->Controls->Add(this->author_textbox);
               this->Controls->Add(this->author_label);
               this->Controls->Add(this->topics_label);
               this->Controls->Add(this->scroll_panel);
               this->Controls->Add(this->dark_bg);
               this->Controls->Add(this->light_bg);
               this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
               this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
               this->Location = System::Drawing::Point(160, 12);
               this->Margin = System::Windows::Forms::Padding(4);
               this->MaximizeBox = false;
               this->MinimizeBox = false;
               this->Name = L"mapwindow";
               this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
               this->Text = L"RoadMap - Progress Map";
               this->dark_bg->ResumeLayout(false);
               this->light_bg->ResumeLayout(false);
               this->light_bg->PerformLayout();
               (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logo))->EndInit();
               this->ResumeLayout(false);
               this->PerformLayout();

           }

#pragma endregion
    private:

        // Drag window

        void draghandlers(System::Windows::Forms::Panel^ panel) {
            panel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mapwindow::window_mousedown);
            panel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &mapwindow::window_mousemove);
            panel->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &mapwindow::window_mouseup);
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

        // Upload button

        System::Void uploadButton_Click(System::Object^ sender, System::EventArgs^ e) {
            openFileDialog1->Filter = "XML Files (*.xml)|*.xml";
            openFileDialog1->FilterIndex = 1;
            openFileDialog1->RestoreDirectory = true;

            if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
                String^ filePath = openFileDialog1->FileName;
                ReadAndDisplayXML(filePath);
            }
        }

		 // Update progress label

        System::Void UpdateProgressLabel() {
            int totalSubtopics = 0;
            int completedSubtopics = 0;

            for each (Control ^ control in scroll_panel->Controls) {
                if (CheckBox^ checkBox = dynamic_cast<CheckBox^>(control)) {
                    totalSubtopics++;
                    if (checkBox->Checked) {
                        completedSubtopics++;
                    }
                }
            }
            if (totalSubtopics > 0) {
                double percentage = (double)completedSubtopics / totalSubtopics * 100;
                progress_label->Text = "Progress: " + completedSubtopics + " / " + totalSubtopics + " (" + percentage.ToString("F2") + "%)";
            }
            else {
                progress_label->Text = "No subtopics available.";
            }
        }

		// Save button

        System::Void ReadAndDisplayXML(String^ filePath) {
            try {
                System::Xml::XmlDocument^ xmlDoc = gcnew System::Xml::XmlDocument();
                xmlDoc->Load(filePath);

                scroll_panel->Controls->Clear();

                System::Xml::XmlNodeList^ rowsNodes = xmlDoc->GetElementsByTagName("ROWS");
                System::Xml::XmlNodeList^ infoNodes = xmlDoc->GetElementsByTagName("MAPINFO");
                System::Xml::XmlNodeList^ dateNodes = xmlDoc->GetElementsByTagName("DATE");

                if (infoNodes->Count > 0) {
                    if (infoNodes[0]->Attributes["Title"] != nullptr) {
                        name_label->Text = infoNodes[0]->Attributes["Title"]->Value;
                    }
                    else {
                        name_label->Text = "Title not found";
                    }

                    if (infoNodes[0]->Attributes["Author"] != nullptr) {
                        author_textbox->Text = infoNodes[0]->Attributes["Author"]->Value;
                    }
                    else {
                        author_textbox->Text = "Author not found";
                    }
                }

                if (dateNodes->Count > 0) {
                    if (dateNodes[0]->Attributes["Deadline"] != nullptr) {
                        String^ deadlineStr = dateNodes[0]->Attributes["Deadline"]->Value;
                        deadline_textbox->Text = deadlineStr;

                        DateTime deadline;
                        if (DateTime::TryParse(deadlineStr, deadline)) {
                            DateTime currentDate = DateTime::Now;
                            TimeSpan remainingTime = deadline - currentDate;

                            if (remainingTime.TotalDays > 0) {
                                if (remainingTime.TotalDays <= 30 && remainingTime.TotalDays > 7) {
                                    MessageBox::Show("The deadline is in less than a month!", "Deadline Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                                }
                                else if (remainingTime.TotalDays <= 7 && remainingTime.TotalDays > 3) {
                                    MessageBox::Show("The deadline is in less than a week!", "Deadline Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                                }
                                else if (remainingTime.TotalDays <= 3 && remainingTime.TotalDays > 1) {
                                    MessageBox::Show("The deadline is in less than 3 days!", "Deadline Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                                }
                                else if (remainingTime.TotalDays <= 1) {
                                    MessageBox::Show("The deadline is tomorrow!", "Deadline Warning", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                                }
                            }
                            else {
                                if (remainingTime.TotalDays == 0) {
                                    MessageBox::Show("Deadline is today!", "Deadline Alert", MessageBoxButtons::OK, MessageBoxIcon::Information);
                                }
                                else {
                                    MessageBox::Show("The deadline has passed!", "Deadline Alert", MessageBoxButtons::OK, MessageBoxIcon::Error);
                                }
                            }
                        }
                        else {
                            MessageBox::Show("Error occurred while saving the Roadmap: Invalid deadline format.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                        }
                    }
                    else {
                        deadline_textbox->Text = "Deadline not found";
                    }
                }
                else {
                    MessageBox::Show("Error occurred while saving the Roadmap: Document element not found.");
                }

                int yOffset = 0;

                for (int i = 0; i < rowsNodes->Count; i++) {
                    String^ Topic = rowsNodes[i]->Attributes["Topic"]->Value;
                    String^ Description = rowsNodes[i]->Attributes["Description"]->Value;
                    String^ Subtopic = rowsNodes[i]->Attributes["Subtopic"]->Value;

                    CreateAndDisplaysubtopics(Topic, Description, Subtopic, yOffset, xmlDoc, "ROWS", i);
                    yOffset += 30 * (Subtopic->Split(',')->Length);
                }

                scroll_panel->AutoScroll = true;
                scroll_panel->AutoScrollMinSize = System::Drawing::Size(0, yOffset);

                UpdateProgressLabel();

            }
            catch (System::Exception^ ex) {
                MessageBox::Show("Error reading file: " + ex->Message);
            }
        }

		// Display subtopics
        
         System::Void CreateAndDisplaysubtopics(String^ topic, String^ description, String^ subtopics, int yOffset, XmlDocument^ xmlDoc, String^ nodeType, int nodeIndex) {

             Label^ topicLabel = gcnew Label();
             topicLabel->AutoSize = true;
             topicLabel->Font = (gcnew System::Drawing::Font(L"Arial", 10.25F, System::Drawing::FontStyle::Bold));
             topicLabel->MaximumSize = System::Drawing::Size(250, 0);
             topicLabel->Location = System::Drawing::Point(0, yOffset);
             topicLabel->Text = topic;
             scroll_panel->Controls->Add(topicLabel);

             Label^ descriptionLabel = gcnew Label();
             descriptionLabel->AutoSize = true;
             descriptionLabel->MaximumSize = System::Drawing::Size(250, 0);
             descriptionLabel->Location = System::Drawing::Point(0, yOffset + 15);
             descriptionLabel->Text = description;
             scroll_panel->Controls->Add(descriptionLabel);

             array<String^>^ subtopicsArray = subtopics->Split(gcnew array<wchar_t>{','}, StringSplitOptions::RemoveEmptyEntries);
             for (int i = 0; i < subtopicsArray->Length; i++) {
                 String^ subtopic = subtopicsArray[i]->Trim();

                 Label^ numberLabel = gcnew Label();
                 numberLabel->AutoSize = true;
                 numberLabel->Font = gcnew System::Drawing::Font(L"Arial", 8.25F, System::Drawing::FontStyle::Bold);
                 numberLabel->Location = System::Drawing::Point(250, yOffset + i * 30);
                 numberLabel->Text = (i + 1).ToString() + ".";
                 scroll_panel->Controls->Add(numberLabel);

                 Label^ subtopicLabel = gcnew Label();
                 subtopicLabel->AutoSize = true;
                 subtopicLabel->MaximumSize = System::Drawing::Size(250, 0);
                 subtopicLabel->Location = System::Drawing::Point(270, yOffset + i * 30);
                 subtopicLabel->Text = subtopic;
                 scroll_panel->Controls->Add(subtopicLabel);

                 CheckBox^ checkBox = gcnew CheckBox();
                 checkBox->Location = System::Drawing::Point(550, yOffset + i * 30);
                 checkBox->Tag = nodeType + ":" + nodeIndex + ":" + i;
                 scroll_panel->Controls->Add(checkBox);

                 XmlNodeList^ nodes = xmlDoc->GetElementsByTagName(nodeType);
                 if (nodeIndex < nodes->Count) {
                     XmlNode^ node = nodes[nodeIndex];
                     String^ attributeName = "Subtopic";
                     if (node->Attributes->GetNamedItem(attributeName)) {
                         String^ subtopics = node->Attributes->GetNamedItem(attributeName)->Value;
                         array<String^>^ subtopicsArray = subtopics->Split(',');
                         if (i < subtopicsArray->Length) {
                             String^ currentsubtopic = subtopicsArray[i]->Trim();
                             if (currentsubtopic->Contains("[+]")) {
                                 checkBox->Checked = true;
                             }
                         }
                     }
                 }
             }
         }

		// Save button

        System::Void saveButton_Click(System::Object^ sender, System::EventArgs^ e) {
            XmlDocument^ xmlDoc = gcnew XmlDocument();
            xmlDoc->Load(openFileDialog1->FileName);

            for each (Control ^ control in scroll_panel->Controls) {
                if (CheckBox^ checkBox = dynamic_cast<CheckBox^>(control)) {
                    array<String^>^ tagParts = checkBox->Tag->ToString()->Split(':');
                    String^ nodeType = tagParts[0];
                    int nodeIndex = Convert::ToInt32(tagParts[1]);
                    int subtopicIndex = Convert::ToInt32(tagParts[2]);

                    XmlNodeList^ nodes = xmlDoc->GetElementsByTagName(nodeType);
                    if (nodeIndex < nodes->Count) {
                        XmlNode^ node = nodes[nodeIndex];
                        String^ attributeName = "Subtopic";
                        if (node->Attributes->GetNamedItem(attributeName)) {
                            String^ subtopics = node->Attributes->GetNamedItem(attributeName)->Value;
                            array<String^>^ subtopicsArray = subtopics->Split(',');
                            if (subtopicIndex < subtopicsArray->Length) {
                                if (checkBox->Checked) {
                                    if (!subtopicsArray[subtopicIndex]->Contains("[+]")) {
                                        subtopicsArray[subtopicIndex] = subtopicsArray[subtopicIndex]->TrimEnd() + " [+]";
                                    }
                                }
                                else {
                                    subtopicsArray[subtopicIndex] = subtopicsArray[subtopicIndex]->Replace(" [+]", "");
                                }
                                String^ newsubtopics = String::Join(",", subtopicsArray);
                                node->Attributes->GetNamedItem(attributeName)->Value = newsubtopics;
                            }
                        }
                    }
                }
            }
            xmlDoc->Save(openFileDialog1->FileName);
            MessageBox::Show("Changes saved successfully!");

            UpdateProgressLabel();
        }
    };
}