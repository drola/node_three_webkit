#define BUILDING_NODE_EXTENSION
#include <node.h>
#include "Vector2.h"
#include "Vector3.h"
#include "Vector4.h"
using namespace v8;

void InitAll(Handle<Object> exports) {
  Vector2::Init(exports);
  Vector3::Init(exports);
  Vector4::Init(exports);
}

NODE_MODULE(math_native, InitAll);