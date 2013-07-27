#define BUILDING_NODE_EXTENSION
#include <node.h>
#include <cmath>
#include "Vector2.h"


using namespace v8;

Vector2::Vector2() {};
Vector2::~Vector2() {};

Persistent<Function> Vector2::constructor;

void Vector2::Init(Handle<Object> exports) {
  // Prepare constructor template
  Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
  tpl->SetClassName(String::NewSymbol("Vector2"));
  tpl->InstanceTemplate()->SetInternalFieldCount(2);

  // Prototype
  tpl->PrototypeTemplate()->Set(String::NewSymbol("set"),
      FunctionTemplate::New(set)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("setX"),
      FunctionTemplate::New(setX)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("setY"),
      FunctionTemplate::New(setY)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("setComponent"),
      FunctionTemplate::New(setComponent)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("getComponent"),
      FunctionTemplate::New(getComponent)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("copy"),
      FunctionTemplate::New(copy)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("add"),
      FunctionTemplate::New(add)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("addVectors"),
      FunctionTemplate::New(addVectors)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("addScalar"),
      FunctionTemplate::New(addScalar)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("sub"),
      FunctionTemplate::New(sub)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("subVectors"),
      FunctionTemplate::New(subVectors)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("multiplyScalar"),
      FunctionTemplate::New(multiplyScalar)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("divideScalar"),
      FunctionTemplate::New(divideScalar)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("min"),
      FunctionTemplate::New(min)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("max"),
      FunctionTemplate::New(max)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("clamp"),
      FunctionTemplate::New(clamp)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("negate"),
      FunctionTemplate::New(negate)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("dot"),
      FunctionTemplate::New(dot)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("lengthSq"),
      FunctionTemplate::New(lengthSq)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("length"),
      FunctionTemplate::New(length)->GetFunction());/*
  tpl->PrototypeTemplate()->Set(String::NewSymbol("normalize"),
      FunctionTemplate::New(normalize)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("distanceTo"),
      FunctionTemplate::New(distanceTo)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("distanceToSquared"),
      FunctionTemplate::New(distanceToSquared)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("setLength"),
      FunctionTemplate::New(setLength)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("lerp"),
      FunctionTemplate::New(lerp)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("equals"),
      FunctionTemplate::New(equals)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("fromArray"),
      FunctionTemplate::New(fromArray)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("toArray"),
      FunctionTemplate::New(toArray)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("clone"),
      FunctionTemplate::New(clone)->GetFunction());*/

  tpl->InstanceTemplate()->SetAccessor(String::New("x"), getVector2X, setVector2X);
  tpl->InstanceTemplate()->SetAccessor(String::New("y"), getVector2Y, setVector2Y);

  constructor = Persistent<Function>::New(tpl->GetFunction());
  exports->Set(String::NewSymbol("Vector2"), constructor);
}

Handle<Value> Vector2::New(const Arguments& args) {
  HandleScope scope;

  Vector2* obj = new Vector2();
  obj->x_ = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
  obj->y_ = args[1]->IsUndefined() ? 0 : args[1]->NumberValue();
  obj->Wrap(args.This());

  return args.This();
}

Handle<Value> Vector2::NewInstance(const Arguments& args) {
  HandleScope scope;
  const unsigned argc = 2;
  Handle<Value> argv[argc] = { args[0], args[1] };
  Local<Object> instance = constructor->NewInstance(argc, argv);
  return scope.Close(instance);
}


Handle<Value> Vector2::set(const Arguments& args) {
  HandleScope scope;

  Vector2* obj = ObjectWrap::Unwrap<Vector2>(args.This());
  obj->x_ = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
  obj->y_ = args[1]->IsUndefined() ? 0 : args[1]->NumberValue(); //TODO: undefined case!!

  return scope.Close(args.This());
}

Handle<Value> Vector2::setX(const Arguments& args) {
  HandleScope scope;

  Vector2* obj = ObjectWrap::Unwrap<Vector2>(args.This());
  obj->x_ = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();

  return scope.Close(args.This());
}

Handle<Value> Vector2::setY(const Arguments& args) {
  HandleScope scope;

  Vector2* obj = ObjectWrap::Unwrap<Vector2>(args.This());
  obj->y_ = args[0]->IsUndefined() ? 0 : args[0]->NumberValue(); //TODO: undefined case!!

  return scope.Close(args.This());
}

Handle<Value> Vector2::setComponent(const Arguments& args) {
  HandleScope scope;
  Vector2* obj = ObjectWrap::Unwrap<Vector2>(args.This());
  int index = args[0]->Int32Value();
  switch(index) {
    case 0:
    obj->x_ = args[1]->NumberValue();
    break;
    case 1:
    obj->y_ = args[1]->NumberValue();
    break;
    default:
    return scope.Close(ThrowException(Exception::Error(String::Concat(String::New("index is out of range: "), args[0]->ToString()))));

  }
  return scope.Close(Undefined());
}

Handle<Value> Vector2::getComponent(const Arguments& args) {
  HandleScope scope;
  Vector2* obj = ObjectWrap::Unwrap<Vector2>(args.This());
  int index = args[0]->Int32Value();
  switch(index) {
    case 0:
    return Number::New(obj->x_);
    break;
    case 1:
    return Number::New(obj->y_);
    break;
    default:
    return scope.Close(ThrowException(Exception::Error(String::Concat(String::New("index is out of range: "), args[0]->ToString()))));
  }
}

Handle<Value> Vector2::copy(const Arguments& args) {
  HandleScope scope;
  Local<Object> obj = args[0]->ToObject();
  if(!obj->Has(String::New("x")) || !obj->Has(String::New("y"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("Cannot copy from object without x and y properties"))));
  }
  args.This()->Set(String::New("x"), obj->Get(String::New("x")));
  args.This()->Set(String::New("y"), obj->Get(String::New("y")));

  return scope.Close(args.This());
}

Handle<Value> Vector2::add(const Arguments& args) {
  HandleScope scope;
  Local<Object> argObj = args[0]->ToObject();
  Vector2* obj = ObjectWrap::Unwrap<Vector2>(args.This());

  if(!argObj->Has(String::New("x")) || !argObj->Has(String::New("y"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("Cannot add from object without x and y properties"))));
  }

  obj->x_ += argObj->Get(String::New("x"))->NumberValue();
  obj->y_ += argObj->Get(String::New("y"))->NumberValue();

  return scope.Close(args.This());
}

Handle<Value> Vector2::addVectors(const Arguments& args) {
  HandleScope scope;
  Local<Object> argObjA = args[0]->ToObject();
  Local<Object> argObjB = args[1]->ToObject();
  Vector2* obj = ObjectWrap::Unwrap<Vector2>(args.This());

  if(!argObjA->Has(String::New("x")) || !argObjA->Has(String::New("y"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("First vector is missing x or y property"))));
  }
  if(!argObjB->Has(String::New("x")) || !argObjB->Has(String::New("y"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("Second vector is missing x or y property"))));
  }

  obj->x_ = argObjA->Get(String::New("x"))->NumberValue() + argObjB->Get(String::New("x"))->NumberValue();
  obj->y_ = argObjA->Get(String::New("y"))->NumberValue() + argObjB->Get(String::New("y"))->NumberValue();

  return scope.Close(args.This());
}

Handle<Value> Vector2::sub(const Arguments& args) {
  HandleScope scope;
  Local<Object> argObj = args[0]->ToObject();
  Vector2* obj = ObjectWrap::Unwrap<Vector2>(args.This());

  if(!argObj->Has(String::New("x")) || !argObj->Has(String::New("y"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("Cannot add from object without x and y properties"))));
  }

  obj->x_ -= argObj->Get(String::New("x"))->NumberValue();
  obj->y_ -= argObj->Get(String::New("y"))->NumberValue();

  return scope.Close(args.This());
}

Handle<Value> Vector2::subVectors(const Arguments& args) {
  HandleScope scope;
  Local<Object> argObjA = args[0]->ToObject();
  Local<Object> argObjB = args[1]->ToObject();
  Vector2* obj = ObjectWrap::Unwrap<Vector2>(args.This());

  if(!argObjA->Has(String::New("x")) || !argObjA->Has(String::New("y"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("First vector is missing x or y property"))));
  }
  if(!argObjB->Has(String::New("x")) || !argObjB->Has(String::New("y"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("Second vector is missing x or y property"))));
  }

  obj->x_ = argObjA->Get(String::New("x"))->NumberValue() - argObjB->Get(String::New("x"))->NumberValue();
  obj->y_ = argObjA->Get(String::New("y"))->NumberValue() - argObjB->Get(String::New("y"))->NumberValue();

  return scope.Close(args.This());
}


Handle<Value> Vector2::addScalar(const Arguments& args) {
  HandleScope scope;
  if(!args[0]->IsNumber()) {
    return scope.Close(ThrowException(Exception::Error(String::New("Only numbers can be added to vector coordinates"))));
  }

  double s = args[0]->NumberValue();
  Vector2* obj = ObjectWrap::Unwrap<Vector2>(args.This());

  obj->x_ += s;
  obj->y_ += s;

  return scope.Close(args.This());
}

Handle<Value> Vector2::multiplyScalar(const Arguments& args) {
  HandleScope scope;
  if(!args[0]->IsNumber()) {
    return scope.Close(ThrowException(Exception::Error(String::New("Given scalar is not a number"))));
  }

  double s = args[0]->NumberValue();
  Vector2* obj = ObjectWrap::Unwrap<Vector2>(args.This());

  obj->x_ *= s;
  obj->y_ *= s;

  return scope.Close(args.This());
}

Handle<Value> Vector2::divideScalar(const Arguments& args) {
  HandleScope scope;
  if(!args[0]->IsNumber()) {
    return scope.Close(ThrowException(Exception::Error(String::New("Given scalar is not a number"))));
  }

  double s = args[0]->NumberValue();
  Vector2* obj = ObjectWrap::Unwrap<Vector2>(args.This());

  if(s != 0) {
    obj->x_ /= s;
    obj->y_ /= s;
  } else {
    obj->x_ = 0;
    obj->y_ = 0;
  }

  return scope.Close(args.This());
}

Handle<Value> Vector2::min(const Arguments& args) {
  HandleScope scope;
  Local<Object> argObj = args[0]->ToObject();
  Vector2* obj = ObjectWrap::Unwrap<Vector2>(args.This());

  if(!argObj->Has(String::New("x")) || !argObj->Has(String::New("y"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("Cannot add from object without x and y properties"))));
  }

  double arg_x = argObj->Get(String::New("x"))->NumberValue();
  double arg_y = argObj->Get(String::New("y"))->NumberValue();
  if(arg_x < obj->x_) {
    obj->x_ = arg_x;
  }
  if(arg_y < obj->y_) {
    obj->y_ = arg_y;
  }
  return scope.Close(args.This());
}

Handle<Value> Vector2::max(const Arguments& args) {
  HandleScope scope;
  Local<Object> argObj = args[0]->ToObject();
  Vector2* obj = ObjectWrap::Unwrap<Vector2>(args.This());

  if(!argObj->Has(String::New("x")) || !argObj->Has(String::New("y"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("Cannot add from object without x and y properties"))));
  }

  double arg_x = argObj->Get(String::New("x"))->NumberValue();
  double arg_y = argObj->Get(String::New("y"))->NumberValue();
  if(arg_x > obj->x_) {
    obj->x_ = arg_x;
  }
  if(arg_y > obj->y_) {
    obj->y_ = arg_y;
  }
  return scope.Close(args.This());
}

Handle<Value> Vector2::clamp(const Arguments& args) {
  HandleScope scope;

  Local<Object> argObjA = args[0]->ToObject();
  Local<Object> argObjB = args[1]->ToObject();
  Vector2* obj = ObjectWrap::Unwrap<Vector2>(args.This());

  if(!argObjA->Has(String::New("x")) || !argObjA->Has(String::New("y"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("First vector is missing x or y property"))));
  }
  if(!argObjB->Has(String::New("x")) || !argObjB->Has(String::New("y"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("Second vector is missing x or y property"))));
  }

  double min_x = argObjA->Get(String::New("x"))->NumberValue();
  double min_y = argObjA->Get(String::New("y"))->NumberValue();
  double max_x = argObjB->Get(String::New("x"))->NumberValue();
  double max_y = argObjB->Get(String::New("y"))->NumberValue();

  if(obj->x_ < min_x) {
    obj->x_ = min_x;
  } else if(obj->x_ > max_x) {
    obj->x_ = max_x;
  }
  if(obj->y_ < min_y) {
    obj->y_ = min_y;
  } else if(obj->y_ > max_y) {
    obj->y_ = max_y;
  }

  return scope.Close(args.This());
}

Handle<Value> Vector2::negate(const Arguments& args) {
  HandleScope scope;
  Vector2* obj = ObjectWrap::Unwrap<Vector2>(args.This());

  obj->x_ *= -1;
  obj->y_ *= -1;

  return scope.Close(args.This());
}

Handle<Value> Vector2::dot(const Arguments& args) {
  HandleScope scope;
  Local<Object> argObj = args[0]->ToObject();
  Vector2* obj = ObjectWrap::Unwrap<Vector2>(args.This());

  if(!argObj->Has(String::New("x")) || !argObj->Has(String::New("y"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("Cannot do dot product with object without x and y properties"))));
  }

  return scope.Close(Number::New(obj->x_ * argObj->Get(String::New("x"))->NumberValue()
    + obj->y_ * argObj->Get(String::New("y"))->NumberValue()));
}

Handle<Value> Vector2::lengthSq(const Arguments& args) {
  HandleScope scope;
  Vector2* obj = ObjectWrap::Unwrap<Vector2>(args.This());

  return scope.Close(Number::New(obj->x_ * obj->x_ + obj->y_ * obj->y_));
}

Handle<Value> Vector2::length(const Arguments& args) {
  HandleScope scope;
  Vector2* obj = ObjectWrap::Unwrap<Vector2>(args.This());

  return scope.Close(Number::New(std::sqrt(obj->x_ * obj->x_ + obj->y_ * obj->y_)));
}

Handle<Value> Vector2::getVector2X(Local<String> property, const AccessorInfo &info) {
  Vector2* obj = ObjectWrap::Unwrap<Vector2>(info.Holder());
  return Number::New(obj->x_);
}

void Vector2::setVector2X(Local<String> property, Local<Value> value, const AccessorInfo &info) {
  Vector2* obj = ObjectWrap::Unwrap<Vector2>(info.Holder());
  obj->x_ = value->NumberValue();
}


Handle<Value> Vector2::getVector2Y(Local<String> property, const AccessorInfo &info) {
  Vector2* obj = ObjectWrap::Unwrap<Vector2>(info.Holder());
  return Number::New(obj->y_);
}

void Vector2::setVector2Y(Local<String> property, Local<Value> value, const AccessorInfo &info) {
  Vector2* obj = ObjectWrap::Unwrap<Vector2>(info.Holder());
  obj->y_ = value->NumberValue();
}