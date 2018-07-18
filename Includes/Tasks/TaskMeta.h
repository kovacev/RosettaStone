/*************************************************************************
> File Name: TaskMeta.h
> Project Name: Hearthstonepp
> Author: Young-Joong Kim
> Purpose: Meta data structure for managing task
> Created Time: 2018/05/20
> Copyright (c) 2018, Young-Joong Kim
*************************************************************************/
#ifndef HEARTHSTONEPP_TASKMETA_H
#define HEARTHSTONEPP_TASKMETA_H

#include <Enums/CardEnums.h>

#include <Flatbuffers/generated/MetaData_generated.h>

#include <memory>

namespace Hearthstonepp
{
using BYTE = unsigned char;

// Abstract of TaskMeta, store default meta data
// `id(TaskID)`, `status(TaskMetaTrait::status_t)`, `accountID(unsigned char)`
struct TaskMetaTrait
{
    using status_t = unsigned int;
    static constexpr status_t STATUS_INVALID = 0;
    static constexpr BYTE USER_INVALID = 255;

    TaskID id;
    status_t status;
    BYTE userID;

    TaskMetaTrait();
    TaskMetaTrait(TaskID id);
    TaskMetaTrait(TaskID id, status_t status);
    TaskMetaTrait(TaskID id, status_t status, BYTE userID);

    TaskMetaTrait(const TaskMetaTrait& trait);

    TaskMetaTrait& operator=(TaskMetaTrait&&) = delete;
    TaskMetaTrait& operator=(const TaskMetaTrait&) = delete;
};

// Meta data of run Task.
class TaskMeta : public TaskMetaTrait
{
 public:
    using status_t = TaskMetaTrait::status_t;

    TaskMeta();
    TaskMeta(const TaskMetaTrait& trait);

    TaskMeta(const TaskMetaTrait& trait, size_t size, const BYTE* buffer);
    TaskMeta(const TaskMetaTrait& trait, size_t size,
             std::unique_ptr<BYTE[]>&& buffer);

    // Non copy-assignable object, only movable.
    // noexcept by move constructor of std::unique_ptr
    TaskMeta(TaskMeta&& meta) noexcept;
    TaskMeta(const TaskMeta&) = delete;

    TaskMeta& operator=(TaskMeta&& meta);
    TaskMeta& operator=(const TaskMeta&) = delete;

    // Deep copy of TaskMeta
    static TaskMeta CopyFrom(const TaskMeta& meta);
    // Convert from FlatData::TaskMeta, deep copy of byte data
    static TaskMeta ConvertFrom(const FlatData::TaskMeta* meta);

    // Reset std::unique_ptr and size data
    void reset();
    size_t GetBufferSize() const;

    std::unique_ptr<BYTE[]>&& MoveBuffer();
    const std::unique_ptr<BYTE[]>& GetConstBuffer() const;

 private:
    size_t m_size;
    std::unique_ptr<BYTE[]> m_buffer;
};
}  // namespace Hearthstonepp

#endif  // HEARTHSTONEPP_TASKMETA_H
