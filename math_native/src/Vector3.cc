#define BUILDING_NODE_EXTENSION
#include <node.h>
#include <cmath>
#include "Vector3.h"
#include "math.h"


using namespace v8;

Vector3::Vector3() {};
Vector3::~Vector3() {};

Persistent<Function> Vector3::constructor;

void Vector3::Init(Handle<Object> exports) {
  // Prepare constructor template
  Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
  tpl->SetClassName(String::NewSymbol("Vector3"));
  tpl->InstanceTemplate()->SetInternalFieldCount(3);

  // Prototype
  tpl->PrototypeTemplate()->Set(String::NewSymbol("set"),
      FunctionTemplate::New(set)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("setX"),
      FunctionTemplate::New(setX)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("setY"),
      FunctionTemplate::New(setY)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("setZ"),
      FunctionTemplate::New(setZ)->GetFunction());
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
      FunctionTemplate::New(length)->GetFunction());
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
      FunctionTemplate::New(equals)->GetFunction());/*
  tpl->PrototypeTemplate()->Set(String::NewSymbol("fromArray"),
      FunctionTemplate::New(fromArray)->GetFunction());
  tpl->PrototypeTemplate()->Set(String::NewSymbol("toArray"),
      FunctionTemplate::New(toArray)->GetFunction());*/
  tpl->PrototypeTemplate()->Set(String::NewSymbol("clone"),
      FunctionTemplate::New(clone)->GetFunction());

  tpl->PrototypeTemplate()->Set(String::NewSymbol("angleTo"),
      FunctionTemplate::New(angleTo)->GetFunction());

  tpl->InstanceTemplate()->SetAccessor(String::New("x"), getVector3X, setVector3X);
  tpl->InstanceTemplate()->SetAccessor(String::New("y"), getVector3Y, setVector3Y);
  tpl->InstanceTemplate()->SetAccessor(String::New("z"), getVector3Z, setVector3Z);

  constructor = Persistent<Function>::New(tpl->GetFunction());
  exports->Set(String::NewSymbol("Vector3"), constructor);
}

Handle<Value> Vector3::New(const Arguments& args) {
  HandleScope scope;

  Vector3* obj = new Vector3();
  obj->x_ = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
  obj->y_ = args[1]->IsUndefined() ? 0 : args[1]->NumberValue();
  obj->z_ = args[1]->IsUndefined() ? 0 : args[2]->NumberValue();
  obj->Wrap(args.This());

  return args.This();
}

Handle<Value> Vector3::NewInstance(const Arguments& args) {
  HandleScope scope;
  const unsigned argc = 3;
  Handle<Value> argv[argc] = { args[0], args[1], args[2] };
  Local<Object> instance = constructor->NewInstance(argc, argv);
  return scope.Close(instance);
}


Handle<Value> Vector3::set(const Arguments& args) {
  HandleScope scope;

  Vector3* obj = ObjectWrap::Unwrap<Vector3>(args.This());
  obj->x_ = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
  obj->y_ = args[1]->IsUndefined() ? 0 : args[1]->NumberValue(); //TODO: undefined case!!
  obj->z_ = args[2]->IsUndefined() ? 0 : args[2]->NumberValue();

  return scope.Close(args.This());
}

Handle<Value> Vector3::setX(const Arguments& args) {
  HandleScope scope;

  Vector3* obj = ObjectWrap::Unwrap<Vector3>(args.This());
  obj->x_ = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();

  return scope.Close(args.This());
}

Handle<Value> Vector3::setY(const Arguments& args) {
  HandleScope scope;

  Vector3* obj = ObjectWrap::Unwrap<Vector3>(args.This());
  obj->y_ = args[0]->IsUndefined() ? 0 : args[0]->NumberValue(); //TODO: undefined case!!

  return scope.Close(args.This());
}

Handle<Value> Vector3::setZ(const Arguments& args) {
  HandleScope scope;

  Vector3* obj = ObjectWrap::Unwrap<Vector3>(args.This());
  obj->z_ = args[0]->IsUndefined() ? 0 : args[0]->NumberValue(); //TODO: undefined case!!

  return scope.Close(args.This());
}


Handle<Value> Vector3::setComponent(const Arguments& args) {
  HandleScope scope;
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(args.This());
  int index = args[0]->Int32Value();
  switch(index) {
    case 0:
    obj->x_ = args[1]->NumberValue();
    break;
    case 1:
    obj->y_ = args[1]->NumberValue();
    break;
    case 2:
    obj->z_ = args[1]->NumberValue();
    break;
    default:
    return scope.Close(ThrowException(Exception::Error(String::Concat(String::New("index is out of range: "), args[0]->ToString()))));

  }
  return scope.Close(Undefined());
}

Handle<Value> Vector3::getComponent(const Arguments& args) {
  HandleScope scope;
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(args.This());
  int index = args[0]->Int32Value();
  switch(index) {
    case 0:
    return Number::New(obj->x_);
    break;
    case 1:
    return Number::New(obj->y_);
    break;
    case 2:
    return Number::New(obj->z_);
    break;
    default:
    return scope.Close(ThrowException(Exception::Error(String::Concat(String::New("index is out of range: "), args[0]->ToString()))));
  }
}

Handle<Value> Vector3::copy(const Arguments& args) {
  HandleScope scope;
  Local<Object> obj = args[0]->ToObject();
  if(!obj->Has(String::New("x")) || !obj->Has(String::New("y")) || !obj->Has(String::New("z"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("Cannot copy from object without x, y and z properties"))));
  }
  args.This()->Set(String::New("x"), obj->Get(String::New("x")));
  args.This()->Set(String::New("y"), obj->Get(String::New("y")));
  args.This()->Set(String::New("z"), obj->Get(String::New("z")));

  return scope.Close(args.This());
}

Handle<Value> Vector3::add(const Arguments& args) {
  HandleScope scope;
  Local<Object> argObj = args[0]->ToObject();
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(args.This());

  if(!argObj->Has(String::New("x")) || !argObj->Has(String::New("y")) || !argObj->Has(String::New("y"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("Cannot add from object without x, y and z properties"))));
  }

  obj->x_ += argObj->Get(String::New("x"))->NumberValue();
  obj->y_ += argObj->Get(String::New("y"))->NumberValue();
  obj->z_ += argObj->Get(String::New("z"))->NumberValue();

  return scope.Close(args.This());
}

Handle<Value> Vector3::addVectors(const Arguments& args) {
  HandleScope scope;
  Local<Object> argObjA = args[0]->ToObject();
  Local<Object> argObjB = args[1]->ToObject();
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(args.This());

  if(!argObjA->Has(String::New("x")) || !argObjA->Has(String::New("y")) || !argObjA->Has(String::New("z"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("First vector is missing x, y or z property"))));
  }
  if(!argObjB->Has(String::New("x")) || !argObjB->Has(String::New("y"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("Second vector is missing x, y or z property"))));
  }

  obj->x_ = argObjA->Get(String::New("x"))->NumberValue() + argObjB->Get(String::New("x"))->NumberValue();
  obj->y_ = argObjA->Get(String::New("y"))->NumberValue() + argObjB->Get(String::New("y"))->NumberValue();
  obj->z_ = argObjA->Get(String::New("z"))->NumberValue() + argObjB->Get(String::New("z"))->NumberValue();

  return scope.Close(args.This());
}

Handle<Value> Vector3::sub(const Arguments& args) {
  HandleScope scope;
  Local<Object> argObj = args[0]->ToObject();
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(args.This());

  if(!argObj->Has(String::New("x")) || !argObj->Has(String::New("y")) || !argObj->Has(String::New("z"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("Cannot add from object without x, y and z properties"))));
  }

  obj->x_ -= argObj->Get(String::New("x"))->NumberValue();
  obj->y_ -= argObj->Get(String::New("y"))->NumberValue();
  obj->z_ -= argObj->Get(String::New("z"))->NumberValue();

  return scope.Close(args.This());
}

Handle<Value> Vector3::subVectors(const Arguments& args) {
  HandleScope scope;
  Local<Object> argObjA = args[0]->ToObject();
  Local<Object> argObjB = args[1]->ToObject();
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(args.This());

  if(!argObjA->Has(String::New("x")) || !argObjA->Has(String::New("y")) || !argObjA->Has(String::New("z"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("First vector is missing x, y or z property"))));
  }
  if(!argObjB->Has(String::New("x")) || !argObjB->Has(String::New("y"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("Second vector is missing x, y or z property"))));
  }

  obj->x_ = argObjA->Get(String::New("x"))->NumberValue() - argObjB->Get(String::New("x"))->NumberValue();
  obj->y_ = argObjA->Get(String::New("y"))->NumberValue() - argObjB->Get(String::New("y"))->NumberValue();
  obj->z_ = argObjA->Get(String::New("z"))->NumberValue() - argObjB->Get(String::New("z"))->NumberValue();

  return scope.Close(args.This());
}


Handle<Value> Vector3::addScalar(const Arguments& args) {
  HandleScope scope;
  if(!args[0]->IsNumber()) {
    return scope.Close(ThrowException(Exception::Error(String::New("Only numbers can be added to vector coordinates"))));
  }

  double s = args[0]->NumberValue();
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(args.This());

  obj->x_ += s;
  obj->y_ += s;
  obj->z_ += s;

  return scope.Close(args.This());
}

Handle<Value> Vector3::multiplyScalar(const Arguments& args) {
  HandleScope scope;
  if(!args[0]->IsNumber()) {
    return scope.Close(ThrowException(Exception::Error(String::New("Given scalar is not a number"))));
  }

  double s = args[0]->NumberValue();
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(args.This());

  obj->x_ *= s;
  obj->y_ *= s;
  obj->z_ *= s;

  return scope.Close(args.This());
}

Handle<Value> Vector3::divideScalar(const Arguments& args) {
  HandleScope scope;
  if(!args[0]->IsNumber()) {
    return scope.Close(ThrowException(Exception::Error(String::New("Given scalar is not a number"))));
  }

  double s = args[0]->NumberValue();
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(args.This());

  if(s != 0) {
    obj->x_ /= s;
    obj->y_ /= s;
    obj->z_ /= s;
  } else {
    obj->x_ = 0;
    obj->y_ = 0;
    obj->z_ = 0;
  }

  return scope.Close(args.This());
}

Handle<Value> Vector3::min(const Arguments& args) {
  HandleScope scope;
  Local<Object> argObj = args[0]->ToObject();
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(args.This());

  if(!argObj->Has(String::New("x")) || !argObj->Has(String::New("y")) || !argObj->Has(String::New("z"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("Cannot add from object without x, y and z properties"))));
  }

  double arg_x = argObj->Get(String::New("x"))->NumberValue();
  double arg_y = argObj->Get(String::New("y"))->NumberValue();
  double arg_z = argObj->Get(String::New("z"))->NumberValue();
  if(arg_x < obj->x_) {
    obj->x_ = arg_x;
  }
  if(arg_y < obj->y_) {
    obj->y_ = arg_y;
  }
  if(arg_z < obj->z_) {
    obj->z_ = arg_z;
  }
  return scope.Close(args.This());
}

Handle<Value> Vector3::max(const Arguments& args) {
  HandleScope scope;
  Local<Object> argObj = args[0]->ToObject();
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(args.This());

  if(!argObj->Has(String::New("x")) || !argObj->Has(String::New("y"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("Cannot add from object without x, y and z properties"))));
  }

  double arg_x = argObj->Get(String::New("x"))->NumberValue();
  double arg_y = argObj->Get(String::New("y"))->NumberValue();
  double arg_z = argObj->Get(String::New("z"))->NumberValue();

  if(arg_x > obj->x_) {
    obj->x_ = arg_x;
  }
  if(arg_y > obj->y_) {
    obj->y_ = arg_y;
  }
  if(arg_z > obj->z_) {
    obj->z_ = arg_z;
  }
  return scope.Close(args.This());
}

Handle<Value> Vector3::clamp(const Arguments& args) {
  HandleScope scope;

  Local<Object> argObjA = args[0]->ToObject();
  Local<Object> argObjB = args[1]->ToObject();
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(args.This());

  if(!argObjA->Has(String::New("x")) || !argObjA->Has(String::New("y")) || !argObjA->Has(String::New("z"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("First vector is missing x, y or z property"))));
  }
  if(!argObjB->Has(String::New("x")) || !argObjB->Has(String::New("y"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("Second vector is missing x, y or z property"))));
  }

  double min_x = argObjA->Get(String::New("x"))->NumberValue();
  double min_y = argObjA->Get(String::New("y"))->NumberValue();
  double min_z = argObjA->Get(String::New("z"))->NumberValue();
  double max_x = argObjB->Get(String::New("x"))->NumberValue();
  double max_y = argObjB->Get(String::New("y"))->NumberValue();
  double max_z = argObjB->Get(String::New("z"))->NumberValue();

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
  if(obj->z_ < min_z) {
    obj->z_ = min_z;
  } else if(obj->z_ > max_z) {
    obj->z_ = max_z;
  }

  return scope.Close(args.This());
}

Handle<Value> Vector3::negate(const Arguments& args) {
  HandleScope scope;
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(args.This());

  obj->x_ *= -1;
  obj->y_ *= -1;
  obj->z_ *= -1;

  return scope.Close(args.This());
}

Handle<Value> Vector3::dot(const Arguments& args) {
  HandleScope scope;
  Local<Object> argObj = args[0]->ToObject();
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(args.This());

  if(!argObj->Has(String::New("x")) || !argObj->Has(String::New("y")) || !argObj->Has(String::New("z"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("Cannot do dot product with object without x, y and z properties"))));
  }

  return scope.Close(Number::New(obj->x_ * argObj->Get(String::New("x"))->NumberValue()
    + obj->y_ * argObj->Get(String::New("y"))->NumberValue()
    + obj->z_ * argObj->Get(String::New("z"))->NumberValue()));
}

Handle<Value> Vector3::lengthSq(const Arguments& args) {
  HandleScope scope;
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(args.This());

  return scope.Close(Number::New(obj->x_ * obj->x_ + obj->y_ * obj->y_ + obj->z_ * obj->z_));
}

Handle<Value> Vector3::length(const Arguments& args) {
  HandleScope scope;
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(args.This());

  return scope.Close(Number::New(std::sqrt(obj->x_ * obj->x_ + obj->y_ * obj->y_ + obj->z_ * obj->z_)));
}

Handle<Value> Vector3::normalize(const Arguments& args) {
  HandleScope scope;
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(args.This());

  double length = std::sqrt(obj->x_ * obj->x_ + obj->y_ * obj->y_ + obj->z_ * obj->z_);
  if(length == 0) {
    obj->x_ = 0;
    obj->y_ = 0;
    obj->z_ = 0;
  } else {
    obj->x_ /= length;
    obj->y_ /= length;
    obj->z_ /= length;
  }

  return scope.Close(args.This());
}

Handle<Value> Vector3::distanceTo(const Arguments& args) {
  HandleScope scope;
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(args.This());

  Local<Object> argObjA = args[0]->ToObject();

  if(!argObjA->Has(String::New("x")) || !argObjA->Has(String::New("y")) || !argObjA->Has(String::New("z"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("Vector is missing x, y or z property"))));
  }

  double x1 = obj->x_;
  double y1 = obj->y_;
  double z1 = obj->z_;
  double x2 = argObjA->Get(String::New("x"))->NumberValue();
  double y2 = argObjA->Get(String::New("y"))->NumberValue();
  double z2 = argObjA->Get(String::New("z"))->NumberValue();
  double dx = x2 - x1;
  double dy = y2 - y1;
  double dz = z2 - z1;

  return scope.Close(Number::New(std::sqrt(dx*dx + dy*dy + dz*dz)));
}

Handle<Value> Vector3::distanceToSquared(const Arguments& args) {
  HandleScope scope;
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(args.This());

  Local<Object> argObjA = args[0]->ToObject();

  if(!argObjA->Has(String::New("x")) || !argObjA->Has(String::New("y")) || !argObjA->Has(String::New("z"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("Vector is missing x, y or z property"))));
  }

  double x1 = obj->x_;
  double y1 = obj->y_;
  double z1 = obj->z_;
  double x2 = argObjA->Get(String::New("x"))->NumberValue();
  double y2 = argObjA->Get(String::New("y"))->NumberValue();
  double z2 = argObjA->Get(String::New("z"))->NumberValue();
  double dx = x2 - x1;
  double dy = y2 - y1;
  double dz = z2 - z1;

  return scope.Close(Number::New(dx*dx + dy*dy + dz*dz));
}

Handle<Value> Vector3::setLength(const Arguments& args) {
  HandleScope scope;
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(args.This());

  if(!args[0]->IsNumber()) {
    return scope.Close(ThrowException(Exception::Error(String::New("Given scalar is not a number"))));
  }

  double newLength = args[0]->NumberValue();
  double length = std::sqrt(obj->x_ * obj->x_ + obj->y_ * obj->y_ + obj->z_ * obj->z_);

  if(length != 0) {
    obj->x_ *= newLength / length;
    obj->y_ *= newLength / length;
    obj->z_ *= newLength / length;
  }

  return scope.Close(args.This());
}

Handle<Value> Vector3::lerp(const Arguments& args) {
  HandleScope scope;
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(args.This());

  Local<Object> argObjA = args[0]->ToObject();
  if(!argObjA->Has(String::New("x")) || !argObjA->Has(String::New("y")) || !argObjA->Has(String::New("z"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("Vector is missing x, y or z property"))));
  }
  double x2 = argObjA->Get(String::New("x"))->NumberValue();
  double y2 = argObjA->Get(String::New("y"))->NumberValue();
  double z2 = argObjA->Get(String::New("z"))->NumberValue();

  if(!args[1]->IsNumber()) {
    return scope.Close(ThrowException(Exception::Error(String::New("Given scalar is not a number"))));
  }

  double alpha = args[1]->NumberValue();

  obj->x_ += ( x2 - obj->x_) * alpha;
  obj->y_ += ( y2 - obj->y_) * alpha;
  obj->z_ += ( z2 - obj->z_) * alpha;

  return scope.Close(args.This());
}

Handle<Value> Vector3::equals(const Arguments& args) {
  HandleScope scope;
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(args.This());

  Local<Object> argObjA = args[0]->ToObject();
  if(!argObjA->Has(String::New("x")) || !argObjA->Has(String::New("y")) || !argObjA->Has(String::New("z"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("Vector is missing x, y or z property"))));
  }
  double x2 = argObjA->Get(String::New("x"))->NumberValue();
  double y2 = argObjA->Get(String::New("y"))->NumberValue();
  double z2 = argObjA->Get(String::New("z"))->NumberValue();


  return scope.Close(Boolean::New(x2 == obj->x_ && y2 == obj->y_ && z2 == obj->z_));
}

Handle<Value> Vector3::clone(const Arguments& args) {
  HandleScope scope;
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(args.This());
  const unsigned argc = 3;
  Handle<Value> argv[argc] = { Number::New(obj->x_), Number::New(obj->y_), Number::New(obj->z_) };
  Local<Object> instance = constructor->NewInstance(argc, argv);
  return scope.Close(instance);
}

Handle<Value> Vector3::angleTo(const Arguments& args) {
  HandleScope scope;
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(args.This());

  Local<Object> argObjA = args[0]->ToObject();
  if(!argObjA->Has(String::New("x")) || !argObjA->Has(String::New("y")) || !argObjA->Has(String::New("z"))) {
    return scope.Close(ThrowException(Exception::Error(String::New("Vector is missing x, y or z property"))));
  }
  double x2 = argObjA->Get(String::New("x"))->NumberValue();
  double y2 = argObjA->Get(String::New("y"))->NumberValue();
  double z2 = argObjA->Get(String::New("z"))->NumberValue();


  return scope.Close(Number::New(
    std::acos( math::clamp( (x2*obj->x_ + y2*obj->y_ + z2*obj->z_) / std::sqrt( (obj->x_ * obj->x_ + obj->y_ * obj->y_ + obj->z_ * obj->z_) * (x2 * x2 + y2*y2 + z2*z2)), -1, 1)
      )));
}


Handle<Value> Vector3::getVector3X(Local<String> property, const AccessorInfo &info) {
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(info.Holder());
  return Number::New(obj->x_);
}

void Vector3::setVector3X(Local<String> property, Local<Value> value, const AccessorInfo &info) {
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(info.Holder());
  obj->x_ = value->NumberValue();
}


Handle<Value> Vector3::getVector3Y(Local<String> property, const AccessorInfo &info) {
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(info.Holder());
  return Number::New(obj->y_);
}

void Vector3::setVector3Y(Local<String> property, Local<Value> value, const AccessorInfo &info) {
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(info.Holder());
  obj->y_ = value->NumberValue();
}

Handle<Value> Vector3::getVector3Z(Local<String> property, const AccessorInfo &info) {
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(info.Holder());
  return Number::New(obj->z_);
}

void Vector3::setVector3Z(Local<String> property, Local<Value> value, const AccessorInfo &info) {
  Vector3* obj = ObjectWrap::Unwrap<Vector3>(info.Holder());
  obj->z_ = value->NumberValue();
}