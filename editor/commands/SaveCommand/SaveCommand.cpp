//
// Created by mrLogic on 10/17/2024.
//

#include "SaveCommand.h"

std::string SaveCommand::HtmlEncode(const std::string &text) {
    std::string encoded;
    for (char c : text)
    {
        switch (c)
        {
            case '<':  encoded += "&lt;"; break;
            case '>':  encoded += "&gt;"; break;
            case '"':  encoded += "&quot;"; break;
            case '\'': encoded += "&apos;"; break;
            case '&':  encoded += "&amp;"; break;
            default:   encoded += c; break;
        }
    }
    return encoded;
}

void SaveCommand::DoExecute()
{
    std::ofstream outFile(m_path);
    if (!outFile.is_open())
    {
        throw std::runtime_error("Unable to open file for writing");
    }
    std::filesystem::path basePath = std::filesystem::path(m_path).parent_path();
    std::filesystem::path imagesDir = basePath / "images";



    outFile << "<!DOCTYPE html>" << std::endl << "<html>" << std::endl << "<head>" << std::endl;
    outFile << "<title>" << HtmlEncode(m_title) << "</title>" << std::endl;
    outFile << "</head>" << std::endl << "<body>" << std::endl ;

    for (const ConstDocumentItem &item : m_documentItems)
    {
        auto paragraph = item.GetParagraph();
        if (paragraph != nullptr)
        {
            outFile << "<p>" << HtmlEncode(paragraph->GetText()) << "</p>" << std::endl;
        }
        auto image = item.GetImage();
        if (image != nullptr)
        {
            if (!std::filesystem::exists(imagesDir))
            {
                std::filesystem::create_directory(imagesDir);
            }
            std::string imagePath = image->GetPath();
            std::string imageFileName = std::filesystem::path(imagePath).filename().string(); 
            std::string destinationPath = (imagesDir / imageFileName).string();

            std::filesystem::copy(imagePath, destinationPath,
                                  std::filesystem::copy_options::overwrite_existing);

            outFile << "<img src=\"" << HtmlEncode("images/" + imageFileName) << "\" "
                    << "width=\"" << image->GetWidth() << "\" "
                    << "height=\"" << image->GetHeight() << "\" "
                    << "alt=\"Image\" />" << std::endl;
        }
    }
    outFile << "</body>" << std::endl << "</html>";
    outFile.close();
}

void SaveCommand::DoUnexecute()
{

}
