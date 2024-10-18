cmake_minimum_required(VERSION 3.24)
project(OOD_5)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)


set(SOURCE_FILES
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
        editor/document/History.cpp
        editor/Menu/Menu.cpp
        editor/Menu/CommandHandler.cpp
)


set(TEST_SOURCE_FILES
        editor/tests/CommandTests.cpp
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
        editor/document/History.cpp
        editor/Menu/Menu.cpp
        editor/Menu/CommandHandler.cpp
        )




add_executable(${PROJECT_NAME} ${SOURCE_FILES})

add_executable(${PROJECT_NAME}_test ${TEST_SOURCE_FILES})
target_link_libraries(${PROJECT_NAME}_test gtest_main gmock gtest)
enable_testing()
add_test(NAME ${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}_test)