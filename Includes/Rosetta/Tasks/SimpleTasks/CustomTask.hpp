// This code is based on Sabberstone project.
// Copyright (c) 2017-2019 SabberStone Team, darkfriend77 & rnilva
// RosettaStone is hearthstone simulator using C++ with reinforcement learning.
// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

#ifndef ROSETTASTONE_CUSTOM_TASK_HPP
#define ROSETTASTONE_CUSTOM_TASK_HPP

#include <Rosetta/Tasks/ITask.hpp>

#include <functional>

namespace RosettaStone::SimpleTasks
{
//!
//! \brief CustomTask class.
//!
//! This class represents the task for running custom function.
//!
class CustomTask : public ITask
{
 public:
    //! Constructs task with given \p func.
    //! \param func The function to run custom task.
    explicit CustomTask(std::function<void(Player*)> func);

 private:
    //! Processes task logic internally and returns meta data.
    //! \param player The player to run task.
    //! \return The result of task processing.
    TaskStatus Impl(Player* player) override;

    //! Internal method of Clone().
    //! \return The cloned task.
    std::unique_ptr<ITask> CloneImpl() override;

    std::function<void(Player*)> m_func;
};
}  // namespace RosettaStone::SimpleTasks

#endif  // ROSETTASTONE_CUSTOM_TASK_HPP
