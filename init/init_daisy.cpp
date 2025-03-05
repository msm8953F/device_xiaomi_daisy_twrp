/*
   Copyright (C) 2021 The Android Open Source Project

   SPDX-License-Identifier: Apache-2.0
 */

#include <cstdlib>
#include <unistd.h>
#include <fcntl.h>
#include <android-base/logging.h>
#include <android-base/properties.h>
#include <sys/resource.h>
#define _REALLY_INCLUDE_SYS__SYSTEM_PROPERTIES_H_
#include <sys/_system_properties.h>


using android::base::GetProperty;

void property_override(const std::string& name, const std::string& value)
{
    size_t valuelen = value.size();

    prop_info* pi = (prop_info*) __system_property_find(name.c_str());
    if (pi != nullptr) {
        __system_property_update(pi, value.c_str(), valuelen);
    }
    else {
        int rc = __system_property_add(name.c_str(), name.size(), value.c_str(), valuelen);
        if (rc < 0) {
            LOG(ERROR) << "property_set(\"" << name << "\", \"" << value << "\") failed: "
                       << "__system_property_add failed";
        }
    }
}

void vendor_load_properties() {
    property_override("ro.bootimage.build.date.utc", "1514797200");
    property_override("ro.build.date.utc", "1514797200");
}

  // namespace init
  // namespace android
