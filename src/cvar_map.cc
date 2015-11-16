// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/cvar_map.h"
#include "../include/functions/sleep_for_ms.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitCvarMap::GitCvarMap(git_cvar_map *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitCvarMap::~GitCvarMap() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitCvarMap::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("CvarMap").ToLocalChecked());

         Nan::SetPrototypeMethod(tpl, "cvarType", CvarType);
         Nan::SetPrototypeMethod(tpl, "strMatch", StrMatch);
         Nan::SetPrototypeMethod(tpl, "mapValue", MapValue);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("CvarMap").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitCvarMap::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitCvarMap cannot be instantiated.");
     }

    GitCvarMap* object = new GitCvarMap(static_cast<git_cvar_map *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitCvarMap::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitCvarMap::constructor_template), 2, argv).ToLocalChecked());
  }

  git_cvar_map *GitCvarMap::GetValue() {
    return this->raw;
  }

  git_cvar_map **GitCvarMap::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitCvarMap::ClearValue() {
    this->raw = NULL;
  }

      NAN_METHOD(GitCvarMap::CvarType) {
      Local<v8::Value> to;

       git_cvar_t
         cvar_type =
         Nan::ObjectWrap::Unwrap<GitCvarMap>(info.This())->GetValue()->cvar_type;
 // start convert_to_v8 block
     to = Nan::New<Number>( cvar_type);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitCvarMap::StrMatch) {
      Local<v8::Value> to;

       const char *
         str_match =
         Nan::ObjectWrap::Unwrap<GitCvarMap>(info.This())->GetValue()->str_match;
 // start convert_to_v8 block
  if (str_match){
       to = Nan::New<String>(str_match).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitCvarMap::MapValue) {
      Local<v8::Value> to;

       int
         map_value =
         Nan::ObjectWrap::Unwrap<GitCvarMap>(info.This())->GetValue()->map_value;
 // start convert_to_v8 block
     to = Nan::New<Number>( map_value);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
    Nan::Persistent<Function> GitCvarMap::constructor_template;
 