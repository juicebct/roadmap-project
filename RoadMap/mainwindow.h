#pragma once
#include "creationwindow.h"
#include "mapwindow.h"
#include "editwindow.h"

namespace RoadMap {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class mainwindow : public System::Windows::Forms::Form
    {
    public:
        mainwindow(void)
        {
            InitializeComponent();
            draghandlers(dark_bg);
            draghandlers(light_bg);
        }

    protected:
        ~mainwindow()
        {
            if (components)
            {
                delete components;
            }
        }

    private: 
        System::ComponentModel::BackgroundWorker^ backgroundWorker1;
        System::Windows::Forms::PictureBox^ logo;
        System::ComponentModel::Container^ components;
        System::Drawing::Point lastPoint;
        System::Windows::Forms::Button^ close_btn;
        System::Windows::Forms::Button^ upload_btn;
        System::Windows::Forms::Button^ edit_btn;
        System::Windows::Forms::Button^ create_btn;
        System::Windows::Forms::Panel^ dark_bg;
        System::Windows::Forms::Label^ choose_label;
        System::Windows::Forms::Label^ version_label;
        System::Windows::Forms::Label^ line_label;
        System::Windows::Forms::LinkLabel^ sourceCode_btn;
    private: System::Windows::Forms::LinkLabel^ dev_btn;

        System::Windows::Forms::Panel^ light_bg;
        System::Windows::Forms::Button^ minimize_btn;
    private: System::Windows::Forms::LinkLabel^ docs_btn;

    private: System::Windows::Forms::Label^ label1;


        bool dragging = false;


    protected:

#pragma region Windows Form Designer generated code

        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(mainwindow::typeid));
            this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
            this->logo = (gcnew System::Windows::Forms::PictureBox());
            this->close_btn = (gcnew System::Windows::Forms::Button());
            this->upload_btn = (gcnew System::Windows::Forms::Button());
            this->edit_btn = (gcnew System::Windows::Forms::Button());
            this->create_btn = (gcnew System::Windows::Forms::Button());
            this->dark_bg = (gcnew System::Windows::Forms::Panel());
            this->minimize_btn = (gcnew System::Windows::Forms::Button());
            this->choose_label = (gcnew System::Windows::Forms::Label());
            this->version_label = (gcnew System::Windows::Forms::Label());
            this->line_label = (gcnew System::Windows::Forms::Label());
            this->sourceCode_btn = (gcnew System::Windows::Forms::LinkLabel());
            this->dev_btn = (gcnew System::Windows::Forms::LinkLabel());
            this->light_bg = (gcnew System::Windows::Forms::Panel());
            this->docs_btn = (gcnew System::Windows::Forms::LinkLabel());
            this->label1 = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logo))->BeginInit();
            this->dark_bg->SuspendLayout();
            this->light_bg->SuspendLayout();
            this->SuspendLayout();
            // 
            // logo
            // 
            resources->ApplyResources(this->logo, L"logo");
            this->logo->Name = L"logo";
            this->logo->TabStop = false;
            // 
            // close_btn
            // 
            this->close_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(21)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
                static_cast<System::Int32>(static_cast<System::Byte>(30)));
            resources->ApplyResources(this->close_btn, L"close_btn");
            this->close_btn->Cursor = System::Windows::Forms::Cursors::Hand;
            this->close_btn->FlatAppearance->BorderColor = System::Drawing::Color::White;
            this->close_btn->FlatAppearance->BorderSize = 0;
            this->close_btn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
            this->close_btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
            this->close_btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(21)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
                static_cast<System::Int32>(static_cast<System::Byte>(26)));
            this->close_btn->Name = L"close_btn";
            this->close_btn->UseVisualStyleBackColor = false;
            this->close_btn->Click += gcnew System::EventHandler(this, &mainwindow::close_btn_Click);
            // 
            // upload_btn
            // 
            this->upload_btn->Cursor = System::Windows::Forms::Cursors::Hand;
            resources->ApplyResources(this->upload_btn, L"upload_btn");
            this->upload_btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(21)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
                static_cast<System::Int32>(static_cast<System::Byte>(26)));
            this->upload_btn->Name = L"upload_btn";
            this->upload_btn->UseVisualStyleBackColor = false;
            this->upload_btn->Click += gcnew System::EventHandler(this, &mainwindow::upload_btn_Click);
            // 
            // edit_btn
            // 
            this->edit_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->edit_btn->Cursor = System::Windows::Forms::Cursors::Hand;
            resources->ApplyResources(this->edit_btn, L"edit_btn");
            this->edit_btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(21)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
                static_cast<System::Int32>(static_cast<System::Byte>(26)));
            this->edit_btn->Name = L"edit_btn";
            this->edit_btn->UseVisualStyleBackColor = false;
            this->edit_btn->Click += gcnew System::EventHandler(this, &mainwindow::edit_btn_Click);
            // 
            // create_btn
            // 
            this->create_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(33)),
                static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->create_btn->Cursor = System::Windows::Forms::Cursors::Hand;
            this->create_btn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)),
                static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(45)));
            this->create_btn->FlatAppearance->BorderSize = 0;
            resources->ApplyResources(this->create_btn, L"create_btn");
            this->create_btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(21)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
                static_cast<System::Int32>(static_cast<System::Byte>(26)));
            this->create_btn->Name = L"create_btn";
            this->create_btn->UseVisualStyleBackColor = false;
            this->create_btn->Click += gcnew System::EventHandler(this, &mainwindow::create_btn_Click);
            // 
            // dark_bg
            // 
            resources->ApplyResources(this->dark_bg, L"dark_bg");
            this->dark_bg->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(21)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
                static_cast<System::Int32>(static_cast<System::Byte>(26)));
            this->dark_bg->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->dark_bg->Controls->Add(this->minimize_btn);
            this->dark_bg->Controls->Add(this->choose_label);
            this->dark_bg->Controls->Add(this->logo);
            this->dark_bg->Controls->Add(this->create_btn);
            this->dark_bg->Controls->Add(this->edit_btn);
            this->dark_bg->Controls->Add(this->upload_btn);
            this->dark_bg->Controls->Add(this->close_btn);
            this->dark_bg->Name = L"dark_bg";
            // 
            // minimize_btn
            // 
            this->minimize_btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(21)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
                static_cast<System::Int32>(static_cast<System::Byte>(30)));
            resources->ApplyResources(this->minimize_btn, L"minimize_btn");
            this->minimize_btn->Cursor = System::Windows::Forms::Cursors::Hand;
            this->minimize_btn->FlatAppearance->BorderColor = System::Drawing::Color::White;
            this->minimize_btn->FlatAppearance->BorderSize = 0;
            this->minimize_btn->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
            this->minimize_btn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::White;
            this->minimize_btn->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(21)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
                static_cast<System::Int32>(static_cast<System::Byte>(26)));
            this->minimize_btn->Name = L"minimize_btn";
            this->minimize_btn->UseVisualStyleBackColor = false;
            this->minimize_btn->Click += gcnew System::EventHandler(this, &mainwindow::minimize_btn_Click);
            // 
            // choose_label
            // 
            resources->ApplyResources(this->choose_label, L"choose_label");
            this->choose_label->ForeColor = System::Drawing::Color::White;
            this->choose_label->Name = L"choose_label";
            // 
            // version_label
            // 
            resources->ApplyResources(this->version_label, L"version_label");
            this->version_label->Name = L"version_label";
            // 
            // line_label
            // 
            resources->ApplyResources(this->line_label, L"line_label");
            this->line_label->Name = L"line_label";
            // 
            // sourceCode_btn
            // 
            this->sourceCode_btn->ActiveLinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)),
                static_cast<System::Int32>(static_cast<System::Byte>(99)), static_cast<System::Int32>(static_cast<System::Byte>(246)));
            resources->ApplyResources(this->sourceCode_btn, L"sourceCode_btn");
            this->sourceCode_btn->ForeColor = System::Drawing::SystemColors::Control;
            this->sourceCode_btn->LinkColor = System::Drawing::Color::Black;
            this->sourceCode_btn->Name = L"sourceCode_btn";
            this->sourceCode_btn->TabStop = true;
            this->sourceCode_btn->VisitedLinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)),
                static_cast<System::Int32>(static_cast<System::Byte>(99)), static_cast<System::Int32>(static_cast<System::Byte>(246)));
            this->sourceCode_btn->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &mainwindow::sourceCode_btn_LinkClicked);
            // 
            // dev_btn
            // 
            this->dev_btn->ActiveLinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
                static_cast<System::Int32>(static_cast<System::Byte>(246)));
            resources->ApplyResources(this->dev_btn, L"dev_btn");
            this->dev_btn->LinkColor = System::Drawing::Color::Black;
            this->dev_btn->Name = L"dev_btn";
            this->dev_btn->TabStop = true;
            this->dev_btn->VisitedLinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
                static_cast<System::Int32>(static_cast<System::Byte>(246)));
            this->dev_btn->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &mainwindow::dev_btn_LinkClicked);
            // 
            // light_bg
            // 
            resources->ApplyResources(this->light_bg, L"light_bg");
            this->light_bg->Controls->Add(this->docs_btn);
            this->light_bg->Controls->Add(this->label1);
            this->light_bg->Controls->Add(this->sourceCode_btn);
            this->light_bg->Controls->Add(this->line_label);
            this->light_bg->Controls->Add(this->dev_btn);
            this->light_bg->Name = L"light_bg";
            // 
            // docs_btn
            // 
            this->docs_btn->ActiveLinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
                static_cast<System::Int32>(static_cast<System::Byte>(246)));
            resources->ApplyResources(this->docs_btn, L"docs_btn");
            this->docs_btn->ForeColor = System::Drawing::SystemColors::Control;
            this->docs_btn->LinkColor = System::Drawing::Color::Black;
            this->docs_btn->Name = L"docs_btn";
            this->docs_btn->TabStop = true;
            this->docs_btn->VisitedLinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(33)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
                static_cast<System::Int32>(static_cast<System::Byte>(246)));
            this->docs_btn->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &mainwindow::docs_btn_LinkClicked);
            // 
            // label1
            // 
            resources->ApplyResources(this->label1, L"label1");
            this->label1->Name = L"label1";
            // 
            // mainwindow
            // 
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
            this->BackColor = System::Drawing::Color::White;
            resources->ApplyResources(this, L"$this");
            this->Controls->Add(this->version_label);
            this->Controls->Add(this->light_bg);
            this->Controls->Add(this->dark_bg);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->Name = L"mainwindow";
            this->TransparencyKey = System::Drawing::SystemColors::WindowFrame;
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->logo))->EndInit();
            this->dark_bg->ResumeLayout(false);
            this->dark_bg->PerformLayout();
            this->light_bg->ResumeLayout(false);
            this->light_bg->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }

#pragma endregion
    private:

        // Drag window

        void draghandlers(System::Windows::Forms::Panel^ panel) {
            panel->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &mainwindow::window_mousedown);
            panel->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &mainwindow::window_mousemove);
            panel->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &mainwindow::window_mouseup);
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
            this->Close();
        }

        // Minimize button

        System::Void minimize_btn_Click(System::Object^ sender, System::EventArgs^ e) {
            this->WindowState = System::Windows::Forms::FormWindowState::Minimized;
        }

		// Create new RoadMap button

        System::Void create_btn_Click(System::Object^ sender, System::EventArgs^ e) {
            creationwindow^ createRoadMap = gcnew creationwindow();
            createRoadMap->Show();
        }

		// Upload RoadMap button

        System::Void upload_btn_Click(System::Object^ sender, System::EventArgs^ e) {
            mapwindow^ progressRoadMap = gcnew mapwindow();
            progressRoadMap->Show();
        }

		// Edit RoadMap button

        System::Void edit_btn_Click(System::Object^ sender, System::EventArgs^ e) {
            editwindow^ editRoadMap = gcnew editwindow();
            editRoadMap->Show();
        }

		// Open source code link

        System::Void sourceCode_btn_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
            System::Diagnostics::Process::Start("https://github.com/juicebct/roadmap-project");
        }

		// Open dev link

        System::Void dev_btn_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
            System::Diagnostics::Process::Start("https://juicebct.github.io/juicebct/");
		}

        // Open docs link

        System::Void docs_btn_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
            System::Diagnostics::Process::Start("https://docs.google.com/document/d/1kklOqX-ad-GdSpk1WSLMWiY8K1Zhq8FAEXWsosPrI90");
        }
    };
}