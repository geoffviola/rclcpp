// Copyright 2015 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef RCLCPP__ANY_EXECUTABLE_HPP_
#define RCLCPP__ANY_EXECUTABLE_HPP_

#include <memory>

#include "rclcpp/macros.hpp"
#include "rclcpp/node.hpp"
#include "rclcpp/visibility_control.hpp"

namespace rclcpp
{
namespace executor
{

struct AnyExecutable
{
  RCLCPP_SMART_PTR_DEFINITIONS(AnyExecutable)

  RCLCPP_PUBLIC
  AnyExecutable();

  RCLCPP_PUBLIC
  virtual ~AnyExecutable();

  // Only one of the following pointers will be set.
  rclcpp::subscription::SubscriptionBase::SharedPtr subscription;
  rclcpp::subscription::SubscriptionBase::SharedPtr subscription_intra_process;
  rclcpp::timer::TimerBase::SharedPtr timer;
  rclcpp::service::ServiceBase::SharedPtr service;
  rclcpp::client::ClientBase::SharedPtr client;
  // These are used to keep the scope on the containing items
  rclcpp::callback_group::CallbackGroup::SharedPtr callback_group;
  rclcpp::node::Node::SharedPtr node;
};

}  // namespace executor
}  // namespace rclcpp

#endif  // RCLCPP__ANY_EXECUTABLE_HPP_
