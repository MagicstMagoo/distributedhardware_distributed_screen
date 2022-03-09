/*
 * Copyright (c) 2022 Huawei Device Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define private public
#include "screen_client_window_adapter_test.h"
#undef private

using namespace testing::ext;

namespace OHOS {
namespace DistributedHardware {
void ScreenClientWindowAdapterTest::SetUpTestCase(void) {}

void ScreenClientWindowAdapterTest::TearDownTestCase(void) {}

void ScreenClientWindowAdapterTest::SetUp() {}

void ScreenClientWindowAdapterTest::TearDown() {}

/**
 * @tc.name: CreateWindow_001
 * @tc.desc: Verify the CreateWindow function.
 * @tc.type: FUNC
 * @tc.require: Issue Number
 */
HWTEST_F(ScreenClientWindowAdapterTest, CreateWindow_001, TestSize.Level1)
{
    std::shared_ptr<WindowProperty> windowProperty = nullptr;
    int32_t windowId = 0;
    sptr<Surface> actualSurface = ScreenClientWindowAdapter::GetInstance().CreateWindow(windowProperty, windowId);
    EXPECT_EQ(nullptr, actualSurface);
}

/**
 * @tc.name: CreateWindow_002
 * @tc.desc: Verify the CreateWindow function.
 * @tc.type: FUNC
 * @tc.require: Issue Number
 */
HWTEST_F(ScreenClientWindowAdapterTest, CreateWindow_002, TestSize.Level1)
{
    std::shared_ptr<WindowProperty> windowProperty = std::make_shared<WindowProperty>();
    int32_t windowId = 2;
    sptr<Surface> surface = nullptr;
    sptr<Surface> actualSurface = ScreenClientWindowAdapter::GetInstance().CreateWindow(windowProperty, windowId);
    EXPECT_NE(surface, actualSurface);
}

/**
 * @tc.name: ShowWindow_001
 * @tc.desc: Verify the ShowWindow function.
 * @tc.type: FUNC
 * @tc.require: Issue Number
 */
HWTEST_F(ScreenClientWindowAdapterTest, ShowWindow_001, TestSize.Level1)
{
    int32_t windowId = 0;
    int32_t actual = ScreenClientWindowAdapter::GetInstance().ShowWindow(windowId);
    EXPECT_EQ(ERR_DH_SCREEN_SCREENCLIENT_SHOW_WINDOW_ERROR, actual);
}

/**
 * @tc.name: ShowWindow_002
 * @tc.desc: Verify the ShowWindow function.
 * @tc.type: FUNC
 * @tc.require: Issue Number
 */
HWTEST_F(ScreenClientWindowAdapterTest, ShowWindow_002, TestSize.Level1)
{
    int32_t windowId = 1;
    int32_t actual = ScreenClientWindowAdapter::GetInstance().ShowWindow(windowId);
    EXPECT_EQ(DH_SUCCESS, actual);
}

/**
 * @tc.name: MoveWindow_001
 * @tc.desc: Verify the MoveWindow function.
 * @tc.type: FUNC
 * @tc.require: Issue Number
 */
HWTEST_F(ScreenClientWindowAdapterTest, MoveWindow_001, TestSize.Level1)
{
    int32_t windowId = 0;
    int32_t startX = 0;
    int32_t startY = 0;
    int32_t actual = ScreenClientWindowAdapter::GetInstance().MoveWindow(windowId, startX, startY);
    EXPECT_EQ(ERR_DH_SCREEN_SCREENCLIENT_MOVE_WINDOW_ERROR, actual);
}

/**
 * @tc.name: MoveWindow_002
 * @tc.desc: Verify the MoveWindow function.
 * @tc.type: FUNC
 * @tc.require: Issue Number
 */
HWTEST_F(ScreenClientWindowAdapterTest, MoveWindow_002, TestSize.Level1)
{
    int32_t windowId = 1;
    int32_t startX = 0;
    int32_t startY = 0;
    int32_t actual = ScreenClientWindowAdapter::GetInstance().MoveWindow(windowId, startX, startY);
    EXPECT_EQ(DH_SUCCESS, actual);
}

/**
 * @tc.name: RemoveWindow_001
 * @tc.desc: Verify the RemoveWindow function.
 * @tc.type: FUNC
 * @tc.require: Issue Number
 */
HWTEST_F(ScreenClientWindowAdapterTest, RemoveWindow_001, TestSize.Level1)
{
    int32_t windowId = 0;
    int32_t actual = ScreenClientWindowAdapter::GetInstance().RemoveWindow(windowId);
    EXPECT_EQ(ERR_DH_SCREEN_SCREENCLIENT_REMOVE_WINDOW_ERROR, actual);
}

/**
 * @tc.name: RemoveWindow_002
 * @tc.desc: Verify the RemoveWindow function.
 * @tc.type: FUNC
 * @tc.require: Issue Number
 */
HWTEST_F(ScreenClientWindowAdapterTest, RemoveWindow_002, TestSize.Level1)
{
    int32_t windowId = 1;
    int32_t actual = ScreenClientWindowAdapter::GetInstance().RemoveWindow(windowId);
    EXPECT_EQ(DH_SUCCESS, actual);
}
}
}