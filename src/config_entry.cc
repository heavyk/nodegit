// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/config_entry.h"
#include "../include/functions/sleep_for_ms.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitConfigEntry::GitConfigEntry(git_config_entry *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitConfigEntry::~GitConfigEntry() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitConfigEntry::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("ConfigEntry").ToLocalChecked());

         Nan::SetPrototypeMethod(tpl, "name", Name);
         Nan::SetPrototypeMethod(tpl, "value", Value);
         Nan::SetPrototypeMethod(tpl, "level", Level);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("ConfigEntry").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitConfigEntry::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitConfigEntry cannot be instantiated.");
     }

    GitConfigEntry* object = new GitConfigEntry(static_cast<git_config_entry *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitConfigEntry::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitConfigEntry::constructor_template), 2, argv).ToLocalChecked());
  }

  git_config_entry *GitConfigEntry::GetValue() {
    return this->raw;
  }

  git_config_entry **GitConfigEntry::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitConfigEntry::ClearValue() {
    this->raw = NULL;
  }

      NAN_METHOD(GitConfigEntry::Name) {
      Local<v8::Value> to;

       const char *
         name =
         Nan::ObjectWrap::Unwrap<GitConfigEntry>(info.This())->GetValue()->name;
 // start convert_to_v8 block
  if (name){
       to = Nan::New<String>(name).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitConfigEntry::Value) {
      Local<v8::Value> to;

       const char *
         value =
         Nan::ObjectWrap::Unwrap<GitConfigEntry>(info.This())->GetValue()->value;
 // start convert_to_v8 block
  if (value){
       to = Nan::New<String>(value).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitConfigEntry::Level) {
      Local<v8::Value> to;

       git_config_level_t
         level =
         Nan::ObjectWrap::Unwrap<GitConfigEntry>(info.This())->GetValue()->level;
 // start convert_to_v8 block
     to = Nan::New<Number>( level);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
    Nan::Persistent<Function> GitConfigEntry::constructor_template;
 