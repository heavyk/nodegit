// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/reflog_entry.h"
#include "../include/functions/sleep_for_ms.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitReflogEntry::GitReflogEntry(git_reflog_entry *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitReflogEntry::~GitReflogEntry() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitReflogEntry::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("ReflogEntry").ToLocalChecked());

  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("ReflogEntry").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitReflogEntry::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitReflogEntry cannot be instantiated.");
     }

    GitReflogEntry* object = new GitReflogEntry(static_cast<git_reflog_entry *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitReflogEntry::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitReflogEntry::constructor_template), 2, argv).ToLocalChecked());
  }

  git_reflog_entry *GitReflogEntry::GetValue() {
    return this->raw;
  }

  git_reflog_entry **GitReflogEntry::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitReflogEntry::ClearValue() {
    this->raw = NULL;
  }

     Nan::Persistent<Function> GitReflogEntry::constructor_template;
 