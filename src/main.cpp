/**
 * The MIT License (MIT)
 *
 * Copyright (c) 2015 Nathan Osman
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to
 * deal in the Software without restriction, including without limitation the
 * rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 * IN THE SOFTWARE.
 **/

#include <QApplication>

#include "application/application.h"
#include "application/splashdialog.h"
#include "settings/settings.h"
#include "config.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    app.setQuitOnLastWindowClosed(false);

    // Set up application properties
    app.setApplicationDisplayName(PROJECT_TITLE);
    app.setApplicationName(PROJECT_TITLE);
    app.setApplicationVersion(PROJECT_VERSION);
    app.setOrganizationDomain(PROJECT_DOMAIN);
    app.setOrganizationName(PROJECT_AUTHOR);

    // Display the spash dialog if this is the first run
    if(!Settings::instance()->get(Settings::Key::ApplicationSplash).toBool()) {
        SplashDialog().exec();
        Settings::instance()->set(Settings::Key::ApplicationSplash, true);
    }

    // Create the tray icon that runs the application
    Application nitroshare;
    Q_UNUSED(nitroshare);

    return app.exec();
}
