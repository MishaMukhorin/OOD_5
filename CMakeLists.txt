cmake_minimum_required(VERSION 3.29)
project(OOD_5)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(OOD_5
        editor/main.cpp
        editor/document/Image.cpp
        editor/document/Paragraph.cpp
        editor/document/DocumentItem.cpp
        editor/document/ConstDocumentItem.cpp
        editor/document/Document.cpp
        editor/commands/InsertParagraphCommand/InsertParagraphCommand.cpp
        editor/commands/AbstractCommand/AbstractCommand.cpp
        editor/commands/SaveCommand/SaveCommand.cpp
        editor/commands/ReplaceTextCommand/ReplaceTextCommand.cpp
        editor/commands/DeleteItemCommand/DeleteItemCommand.cpp
        editor/commands/InsertImageCommand/InsertImageCommand.cpp
        editor/commands/SetTitleCommand/SetTitleCommand.cpp
        editor/commands/ResizeImageCommand/ResizeImageCommand.cpp
        editor/commands/CompoundCommand/AbstractUndoable.cpp
        editor/commands/CompoundCommand/CompoundCommand.cpp
        editor/document/History.cpp
        editor/Menu/Menu.cpp
        editor/Menu/CommandHandler.cpp
)
