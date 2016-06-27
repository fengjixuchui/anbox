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

#include "android/service/daemon.h"
#include "android/service/host_connector.h"

#include "core/posix/signal.h"

#include <memory>

#include <cstdlib>

namespace anbox {
namespace android {
Daemon::Daemon() {
}

Daemon::~Daemon() {
}

int Daemon::run() {
    auto trap = core::posix::trap_signals_for_process({core::posix::Signal::sig_term,
                                                       core::posix::Signal::sig_int});
    trap->signal_raised().connect([trap](const core::posix::Signal&) {
        trap->stop();
    });

    auto host_connector = std::make_shared<HostConnector>();

    trap->run();

    return EXIT_SUCCESS;
}
} // namespace android
} // namespace anbox
