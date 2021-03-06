// This code is based on Sabberstone project.
// Copyright (c) 2017-2019 SabberStone Team, darkfriend77 & rnilva
// RosettaStone is hearthstone simulator using C++ with reinforcement learning.
// Copyright (c) 2019 Chris Ohk, Youngjoong Kim, SeungHyun Jeon

#ifndef ROSETTASTONE_CONTROL_TASK_HPP
#define ROSETTASTONE_CONTROL_TASK_HPP

#include <Rosetta/Tasks/ITask.hpp>

namespace RosettaStone::SimpleTasks
{
//!
//! \brief ControlTask class.
//!
//! This class represents the task for taking control.
//!
class ControlTask : public ITask
{
 public:
    //! Constructs task with given \p entityType.
    //! \param entityType The entity type of target to take control.
    //! \param opposite The flag that indicates the owner is the opponent.
    explicit ControlTask(EntityType entityType, bool opposite = false);

 private:
    //! Processes task logic internally and returns meta data.
    //! \param player The player to run task.
    //! \return The result of task processing.
    TaskStatus Impl(Player* player) override;

    //! Internal method of Clone().
    //! \return The cloned task.
    std::unique_ptr<ITask> CloneImpl() override;

    bool m_opposite = false;
};
}  // namespace RosettaStone::SimpleTasks

#endif  // ROSETTASTONE_CONTROL_TASK_HPP
