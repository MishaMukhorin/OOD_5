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
    // Вставляет параграф текста в указанную позицию (сдвигая последующие элементы)
    // Если параметр position не указан, вставка происходит в конец документа
    [[maybe_unused]] [[nodiscard]] virtual std::shared_ptr<IParagraph> InsertParagraphImpl(const std::string& text,
                                                   std::optional<size_t> position) = 0;

    // Вставляет изображение в указанную позицию (сдвигая последующие элементы)
    // Параметр path задает путь к вставляемому изображению
    // При вставке изображение должно копироваться в подкаталог images
    // под автоматически сгенерированным именем
    [[maybe_unused]] [[nodiscard]] virtual std::shared_ptr<IImage> InsertImageImpl(const std::string& path, int width, int height,
                                           std::optional<size_t> position) = 0;

    // Возвращает количество элементов в документе
    [[nodiscard]] virtual size_t GetItemsCount()const = 0;

    // Доступ к элементам изображения
    [[nodiscard]] virtual ConstDocumentItem GetItem(size_t index) const = 0;
    [[nodiscard]] virtual DocumentItem GetItem(size_t index) = 0;

    // Удаляет элемент из документа
    virtual void DeleteItem(size_t index) = 0;

    // Возвращает заголовок документа
    [[nodiscard]] virtual std::string GetTitle()const = 0;

    // Изменяет заголовок документа
    virtual void SetTitle(const std::string & title) = 0;

    // Сообщает о доступности операции Undo
    [[nodiscard]] virtual bool CanUndo()const = 0;

    // Отменяет команду редактирования
    virtual void Undo() = 0;

    // Сообщает о доступности операции Redo
    [[nodiscard]] virtual bool CanRedo()const = 0;

    // Выполняет отмененную команду редактирования
    virtual void Redo() = 0;

    // Сохраняет документ в формате html. Изображения сохраняются в подкаталог images.
    // Пути к изображениям указываются относительно пути к сохраняемому HTML файлу
    virtual void Save(const std::string& path)const = 0;

    virtual ~IDocument() = default;
};

#endif //OOD_5_IDOCUMENT_H
