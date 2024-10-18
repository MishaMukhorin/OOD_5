//
// Created by mrLogic on 10/17/2024.
//

#include "CommandHandler.h"

CommandHandler::CommandHandler(Menu &menu, Document &document)
        : m_menu(menu), m_document(document)
{
    m_menu.AddItem("Help", "Help", [this](std::istream&) { m_menu.ShowInstructions(); });
    AddMenuItem(InsertParagraphCommand::name, "Insert paragraph", &CommandHandler::InsertParagraph);
    AddMenuItem(InsertImageCommand::name, "Insert image", &CommandHandler::InsertImage);
    AddMenuItem("List", "Show document", &CommandHandler::List);
    AddMenuItem(SetTitleCommand::name, "Set title", &CommandHandler::SetTitle);
    AddMenuItem(ReplaceTextCommand::name, "Replace text", &CommandHandler::ReplaceText);
    AddMenuItem(ResizeImageCommand::name, "Resize Image", &CommandHandler::ResizeImage);
    AddMenuItem(DeleteItemCommand::name, "Delete item", &CommandHandler::DeleteItem);
    AddMenuItem("Undo", "Undo command", &CommandHandler::Undo);
    AddMenuItem("Redo", "Redo undone command", &CommandHandler::Redo);
    AddMenuItem("Save", "Save to html", &CommandHandler::Save);
}

void CommandHandler::AddMenuItem(const std::string &commandName, const std::string &description,
                                 CommandHandler::MenuHandler handler)
{
    m_menu.AddItem(commandName, description, [this, handler](std::istream& input) {
        (this->*handler)(input);
    });
}

void CommandHandler::List(std::istream &)
{
    std::cout << "Title " << m_document.GetTitle() << "\n";

    for (int i = 0; i < m_document.GetItemsCount(); i++)
    {
        auto documentItem = m_document.GetItem(i);
        auto paragraph = documentItem.GetParagraph();
        if (paragraph != nullptr)
        {
            std::cout << (i) << ". Paragrpah: " << paragraph->GetText() << "\n";
        }

        auto image = documentItem.GetImage();
        if (image != nullptr)
        {
            std::cout<< (i) << ". Image: " << image->GetWidth() << " " << image->GetHeight() << " " << image->GetPath() << "\n";
        }
    }
}

void CommandHandler::InsertParagraph(std::istream &in)
{
    std::string text;
    std::string positionStr;

    in >> positionStr >> text;

    std::optional<size_t> position;
    if (positionStr == "end")
    {
        position = std::nullopt;
    }
    else
    {
        try
        {
            position = std::stoi(positionStr);
        }
        catch (...)
        {
            throw std::invalid_argument("Invalid type position");
        }
    }

    m_document.InsertParagraph(text, position);
}

void CommandHandler::SetTitle(std::istream &in)
{
    std::string title;

    in >> title;

    m_document.SetTitle(title);
}

void CommandHandler::ReplaceText(std::istream &in)
{
    std::string newText;
    std::string positionStr;

    in >> positionStr >> newText;

    std::optional<size_t> position;
    try
    {
        position = std::stoi(positionStr);
    }
    catch (...)
    {
        throw std::invalid_argument("Invalid type position");
    }

    m_document.ReplaceText(newText, position);
}

void CommandHandler::DeleteItem(std::istream &in)
{
    std::string positionStr;

    in >> positionStr;

    size_t position;
    try
    {
        position = std::stoi(positionStr);
    }
    catch (...)
    {
        throw std::invalid_argument("Invalid type position");
    }

    m_document.DeleteItem(position);
}

void CommandHandler::Undo(std::istream &)
{
    if (m_document.CanUndo())
    {
        m_document.Undo();
    }
    else
    {
        std::cout << "Can't undo" << std::endl;
    }
}

void CommandHandler::Redo(std::istream &)
{
    if (m_document.CanRedo())
    {
        m_document.Redo();
    }
    else
    {
        std::cout << "Can't redo" << std::endl;
    }
}

void CommandHandler::Save(std::istream &in)
{
    std::string path;

    in >> path;

    m_document.Save(path);
}

void CommandHandler::InsertImage(std::istream &in)
{
    std::string path, width, height, positionStr;

    in >> positionStr >> width >> height >> path ;

    std::optional<size_t> position;
    int widthNum, heightNum;

    if (positionStr == "end")
    {
        position = std::nullopt;
    }
    else
    {
        try
        {
            position = std::stoi(positionStr);
        }
        catch (...)
        {
            throw std::invalid_argument("Invalid type position number");
        }
    }
    try
    {
        widthNum = std::stoi(width);
        heightNum = std::stoi(height);
    }
    catch (...)
    {
        throw std::invalid_argument("Invalid type number");
    }
    m_document.InsertImage(path, widthNum, heightNum, position);
}
void CommandHandler::ResizeImage(std::istream &in)
{
    std::string newWidth, newHeight;
    std::string positionStr;

    in >> positionStr >> newWidth >> newHeight;
    int width, height;
    std::optional<size_t> position;
    try
    {
        position = std::stoi(positionStr);
        width = std::stoi(newWidth);
        height = std::stoi(newHeight);
    }
    catch (...)
    {
        throw std::invalid_argument("Invalid type number");
    }

    m_document.ResizeImage(width, height, position);
}



