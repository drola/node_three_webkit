#ifndef VECTOR3_H
#define VECTOR3_H

#include <node.h>

class Vector3 : public node::ObjectWrap {
 public:
  static void Init(v8::Handle<v8::Object> exports);

 private:
  Vector3();
  ~Vector3();
  static v8::Persistent<v8::Function> constructor;

  static v8::Handle<v8::Value> New(const v8::Arguments& args);
  static v8::Handle<v8::Value> NewInstance(const v8::Arguments& args);
  static v8::Handle<v8::Value> set(const v8::Arguments& args);
  static v8::Handle<v8::Value> setX(const v8::Arguments& args);
  static v8::Handle<v8::Value> setY(const v8::Arguments& args);
  static v8::Handle<v8::Value> setZ(const v8::Arguments& args);
  static v8::Handle<v8::Value> setComponent(const v8::Arguments& args);
  static v8::Handle<v8::Value> getComponent(const v8::Arguments& args);
  static v8::Handle<v8::Value> copy(const v8::Arguments& args);
  static v8::Handle<v8::Value> add(const v8::Arguments& args);
  static v8::Handle<v8::Value> addVectors(const v8::Arguments& args);
  static v8::Handle<v8::Value> addScalar(const v8::Arguments& args);
  static v8::Handle<v8::Value> sub(const v8::Arguments& args);
  static v8::Handle<v8::Value> subVectors(const v8::Arguments& args);
  static v8::Handle<v8::Value> multiplyScalar(const v8::Arguments& args);
  static v8::Handle<v8::Value> divideScalar(const v8::Arguments& args);
  static v8::Handle<v8::Value> min(const v8::Arguments& args);
  static v8::Handle<v8::Value> max(const v8::Arguments& args);
  static v8::Handle<v8::Value> clamp(const v8::Arguments& args);
  static v8::Handle<v8::Value> negate(const v8::Arguments& args);
  static v8::Handle<v8::Value> dot(const v8::Arguments& args);
  static v8::Handle<v8::Value> lengthSq(const v8::Arguments& args);
  static v8::Handle<v8::Value> length(const v8::Arguments& args);
  static v8::Handle<v8::Value> normalize(const v8::Arguments& args);
  static v8::Handle<v8::Value> distanceTo(const v8::Arguments& args);
  static v8::Handle<v8::Value> distanceToSquared(const v8::Arguments& args);
  static v8::Handle<v8::Value> setLength(const v8::Arguments& args);
  static v8::Handle<v8::Value> lerp(const v8::Arguments& args);
  static v8::Handle<v8::Value> equals(const v8::Arguments& args);
  static v8::Handle<v8::Value> fromArray(const v8::Arguments& args);
  static v8::Handle<v8::Value> toArray(const v8::Arguments& args);
  static v8::Handle<v8::Value> clone(const v8::Arguments& args);

  static v8::Handle<v8::Value> angleTo(const v8::Arguments& args);

  static v8::Handle<v8::Value> getVector3X(v8::Local<v8::String> property, const v8::AccessorInfo& info);
  static void setVector3X(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
  static v8::Handle<v8::Value> getVector3Y(v8::Local<v8::String> property, const v8::AccessorInfo& info);
  static void setVector3Y(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);
  static v8::Handle<v8::Value> getVector3Z(v8::Local<v8::String> property, const v8::AccessorInfo& info);
  static void setVector3Z(v8::Local<v8::String> property, v8::Local<v8::Value> value, const v8::AccessorInfo& info);

  double x_;
  double y_;
  double z_;
};

#endif