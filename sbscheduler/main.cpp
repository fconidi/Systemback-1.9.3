/*
 * Copyright(C) 2014-2016, Franco Conidi <nemh@freemail.hu>
 *
 * This file is part of the Systemback.
 *
 * The Systemback is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 3 of the License, or (at your option) any later
 * version.
 *
 * The Systemback is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with the
 * Systemback. If not, see <http://www.gnu.org/licenses>.
 */

#include "sbscheduler.hpp"
#include <QTimer>

QDateTime scheduler::cfglmd;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    sb::ldtltr();
    scheduler s;

    QTimer::singleShot(0, &s,
#if QT_VERSION < QT_VERSION_CHECK(5, 4, 0)
        SLOT(main())
#else
        &scheduler::main
#endif
        );

    uchar rv(a.exec());
    return rv;
}
