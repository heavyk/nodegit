// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/merge_result.h"
#include "../include/functions/sleep_for_ms.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitMergeResult::GitMergeResult(git_merge_result *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitMergeResult::~GitMergeResult() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitMergeResult::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("MergeResult").ToLocalChecked());

  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("MergeResult").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitMergeResult::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitMergeResult cannot be instantiated.");
     }

    GitMergeResult* object = new GitMergeResult(static_cast<git_merge_result *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitMergeResult::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitMergeResult::constructor_template), 2, argv).ToLocalChecked());
  }

  git_merge_result *GitMergeResult::GetValue() {
    return this->raw;
  }

  git_merge_result **GitMergeResult::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitMergeResult::ClearValue() {
    this->raw = NULL;
  }

     Nan::Persistent<Function> GitMergeResult::constructor_template;
 