#include "gtest/gtest.h"
#include <QCoreApplication>
#include <QObject>
#include <QTimer>

int testResult{};
static void runTestCallback() {
  testResult = RUN_ALL_TESTS();
  QCoreApplication::quit();
}

int main(int argc, char *argv[]) {
  QCoreApplication app(argc, argv);
  testing::InitGoogleTest(&argc, argv);

  QTimer testStart(&app);
  QObject::connect(&testStart, &QTimer::timeout, &runTestCallback);
  testStart.start(500);
  app.exec();
  return testResult;
}
