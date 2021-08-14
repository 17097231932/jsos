/* File generated automatically by the QuickJS compiler. */

#include "quickjs-libc.h"

#define jscode "console.log('Hello,', 'World!')"

static JSContext *JS_NewCustomContext(JSRuntime *rt) {
    JSContext *ctx = JS_NewContextRaw(rt);
    if (!ctx)
        return NULL;
    JS_AddIntrinsicBaseObjects(ctx);
    JS_AddIntrinsicDate(ctx);
    JS_AddIntrinsicEval(ctx);
    JS_AddIntrinsicStringNormalize(ctx);
    JS_AddIntrinsicRegExp(ctx);
    JS_AddIntrinsicJSON(ctx);
    JS_AddIntrinsicProxy(ctx);
    JS_AddIntrinsicMapSet(ctx);
    JS_AddIntrinsicTypedArrays(ctx);
    JS_AddIntrinsicPromise(ctx);
    return ctx;
}

int main(int argc, char **argv) {
    JSRuntime *rt;
    JSContext *ctx;
    rt = JS_NewRuntime();
    js_std_init_handlers(rt);
    JS_SetModuleLoaderFunc(rt, NULL, js_module_loader, NULL);
    ctx = JS_NewCustomContext(rt);
    js_std_add_helpers(ctx, argc, argv);
    JSValue binary = JS_Eval(ctx, jscode, sizeof(jscode) - 1, "<global>",
                             JS_EVAL_FLAG_COMPILE_ONLY);
    if (JS_IsException(binary)) {
        js_std_dump_error(ctx);
        return -1;
    }
    JSValue val = JS_EvalFunction(ctx, binary);
    if (JS_IsException(val)) {
        js_std_dump_error(ctx);
        return -1;
    }
    js_std_loop(ctx);
    JS_FreeContext(ctx);
    JS_FreeRuntime(rt);
    return 0;
}
