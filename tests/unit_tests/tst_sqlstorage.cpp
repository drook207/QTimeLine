#include "sqlstorage.h"
#include "gtest/gtest.h"

using namespace testing;

TEST(tst_sqlStorage, createStorageFromFile) {

  const QString filename = QStringLiteral("test.db");
  auto storage = QTimeLine::SqlStorage::fromFile(filename);
  ASSERT_FALSE(storage.isNull());
}

TEST(tst_sqlStorage, createInavlidStorageFromFileWithEmptyName) {

  const QString filename = QStringLiteral("");
  auto storage = QTimeLine::SqlStorage::fromFile(filename);
  ASSERT_TRUE(storage.isNull());
}
