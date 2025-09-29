#include "miniaudio.h"
#include <hx/CFFIPrime.h>
#include <stdint.h>
#include <stdlib.h>

// Helper macro to convert Haxe value -> intptr_t
#define VAL_TO_PTR(v) ((intptr_t)val_int(v))

// Context
ma_result ma_context_init_wrapper(value contextVal) {
    ma_context* ctx = (ma_context*)VAL_TO_PTR(contextVal);
    return ma_context_init(NULL, 0, NULL, ctx);
}

void ma_context_uninit_wrapper(value contextVal) {
    ma_context* ctx = (ma_context*)VAL_TO_PTR(contextVal);
    ma_context_uninit(ctx);
}

// Device config
value ma_device_config_init_wrapper(value typeVal) {
    ma_device_type type = (ma_device_type)val_int(typeVal);
    ma_device_config* cfg = (ma_device_config*)malloc(sizeof(ma_device_config));
    *cfg = ma_device_config_init(type);
    return alloc_int((intptr_t)cfg);
}

// Device
ma_result ma_device_init_wrapper(value contextVal, value cfgVal, value deviceVal) {
    ma_context* ctx = (ma_context*)VAL_TO_PTR(contextVal);
    ma_device_config* cfg = (ma_device_config*)VAL_TO_PTR(cfgVal);
    ma_device* dev = (ma_device*)VAL_TO_PTR(deviceVal);
    return ma_device_init(ctx, cfg, dev);
}

ma_result ma_device_start_wrapper(value deviceVal) {
    ma_device* dev = (ma_device*)VAL_TO_PTR(deviceVal);
    return ma_device_start(dev);
}

ma_result ma_device_stop_wrapper(value deviceVal) {
    ma_device* dev = (ma_device*)VAL_TO_PTR(deviceVal);
    return ma_device_stop(dev);
}

void ma_device_uninit_wrapper(value deviceVal) {
    ma_device* dev = (ma_device*)VAL_TO_PTR(deviceVal);
    ma_device_uninit(dev);
}

// ---- CFFI bindings ----
DEFINE_PRIME1(ma_context_init_wrapper)
DEFINE_PRIME1v(ma_context_uninit_wrapper)
DEFINE_PRIME1(ma_device_config_init_wrapper)
DEFINE_PRIME3(ma_device_init_wrapper)
DEFINE_PRIME1(ma_device_start_wrapper)
DEFINE_PRIME1(ma_device_stop_wrapper)
DEFINE_PRIME1v(ma_device_uninit_wrapper)
