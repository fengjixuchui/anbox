/*
 * Copyright (C) 2016 Simon Fels <morphis@gravedo.de>
 *
 * This program is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 3, as published
 * by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranties of
 * MERCHANTABILITY, SATISFACTORY QUALITY, or FITNESS FOR A PARTICULAR
 * PURPOSE.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#ifndef ANBOX_ANDROID_MESSAGE_PROCESSOR_H_
#define ANBOX_ANDROID_MESSAGE_PROCESSOR_H_

#include "anbox/bridge/message_processor.h"

namespace anbox {
namespace android {
class Server;
class MessageProcessor : public bridge::MessageProcessor {
public:
    MessageProcessor(const std::shared_ptr<network::MessageSender> &sender,
                     const std::shared_ptr<bridge::PendingCallCache> &pending_calls,
                     const std::shared_ptr<Server> &server);
    ~MessageProcessor();

    void dispatch(bridge::Invocation const& invocation) override;
    void process_event_sequence(const std::string &event) override;

private:
    std::shared_ptr<Server> server_;
};
} // namespace anbox
} // namespace network

#endif
