// Copyright 2013 The Flutter Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef FLUTTER_SHELL_COMMON_SNAPSHOT_CONTROLLER_SKIA_H_
#define FLUTTER_SHELL_COMMON_SNAPSHOT_CONTROLLER_SKIA_H_

#include "flutter/shell/common/snapshot_controller.h"
#include "third_party/skia/include/core/SkSurface.h"

namespace flutter {

class SnapshotControllerSkia : public SnapshotController {
 public:
  explicit SnapshotControllerSkia(const SnapshotController::Delegate& delegate)
      : SnapshotController(delegate) {}

  sk_sp<DlImage> MakeRasterSnapshot(sk_sp<DisplayList> display_list,
                                    SkISize size) override;

  sk_sp<DlImage> MakeRasterSnapshot(
      const std::shared_ptr<const impeller::Picture>& picture,
      SkISize size) override;

  virtual sk_sp<SkImage> ConvertToRasterImage(sk_sp<SkImage> image) override;

 private:
  sk_sp<DlImage> DoMakeRasterSnapshot(
      SkISize size,
      std::function<void(SkCanvas*)> draw_callback);

  FML_DISALLOW_COPY_AND_ASSIGN(SnapshotControllerSkia);
};

}  // namespace flutter

#endif  // FLUTTER_SHELL_COMMON_SNAPSHOT_CONTROLLER_SKIA_H_
