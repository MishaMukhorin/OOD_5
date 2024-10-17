//
// Created by mrLogic on 10/17/2024.
//

#ifndef OOD_5_IDOCUMENT_H
#define OOD_5_IDOCUMENT_H

#include <optional>
#include "DocumentItem.h"

class IDocument
{
public:
    // ��������� �������� ������ � ��������� ������� (������� ����������� ��������)
    // ���� �������� position �� ������, ������� ���������� � ����� ���������
    [[maybe_unused]] [[nodiscard]] virtual std::shared_ptr<IParagraph> InsertParagraphImpl(const std::string& text,
                                                   std::optional<size_t> position) = 0;

    // ��������� ����������� � ��������� ������� (������� ����������� ��������)
    // �������� path ������ ���� � ������������ �����������
    // ��� ������� ����������� ������ ������������ � ���������� images
    // ��� ������������� ��������������� ������
    [[maybe_unused]] [[nodiscard]] virtual std::shared_ptr<IImage> InsertImageImpl(const std::string& path, int width, int height,
                                           std::optional<size_t> position) = 0;

    // ���������� ���������� ��������� � ���������
    [[nodiscard]] virtual size_t GetItemsCount()const = 0;

    // ������ � ��������� �����������
    [[nodiscard]] virtual ConstDocumentItem GetItem(size_t index) const = 0;
    [[nodiscard]] virtual DocumentItem GetItem(size_t index) = 0;

    // ������� ������� �� ���������
    virtual void DeleteItem(size_t index) = 0;

    // ���������� ��������� ���������
    [[nodiscard]] virtual std::string GetTitle()const = 0;

    // �������� ��������� ���������
    virtual void SetTitle(const std::string & title) = 0;

    // �������� � ����������� �������� Undo
    [[nodiscard]] virtual bool CanUndo()const = 0;

    // �������� ������� ��������������
    virtual void Undo() = 0;

    // �������� � ����������� �������� Redo
    [[nodiscard]] virtual bool CanRedo()const = 0;

    // ��������� ���������� ������� ��������������
    virtual void Redo() = 0;

    // ��������� �������� � ������� html. ����������� ����������� � ���������� images.
    // ���� � ������������ ����������� ������������ ���� � ������������ HTML �����
    virtual void Save(const std::string& path)const = 0;

    virtual ~IDocument() = default;
};

#endif //OOD_5_IDOCUMENT_H
