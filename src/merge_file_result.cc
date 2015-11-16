// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/merge_file_result.h"
#include "../include/functions/sleep_for_ms.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitMergeFileResult::GitMergeFileResult(git_merge_file_result *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitMergeFileResult::~GitMergeFileResult() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitMergeFileResult::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("MergeFileResult").ToLocalChecked());

         Nan::SetPrototypeMethod(tpl, "automergeable", Automergeable);
         Nan::SetPrototypeMethod(tpl, "path", Path);
         Nan::SetPrototypeMethod(tpl, "mode", Mode);
         Nan::SetPrototypeMethod(tpl, "ptr", Ptr);
         Nan::SetPrototypeMethod(tpl, "len", Len);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("MergeFileResult").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitMergeFileResult::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitMergeFileResult cannot be instantiated.");
     }

    GitMergeFileResult* object = new GitMergeFileResult(static_cast<git_merge_file_result *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitMergeFileResult::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitMergeFileResult::constructor_template), 2, argv).ToLocalChecked());
  }

  git_merge_file_result *GitMergeFileResult::GetValue() {
    return this->raw;
  }

  git_merge_file_result **GitMergeFileResult::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitMergeFileResult::ClearValue() {
    this->raw = NULL;
  }

      NAN_METHOD(GitMergeFileResult::Automergeable) {
      Local<v8::Value> to;

       unsigned int
         automergeable =
         Nan::ObjectWrap::Unwrap<GitMergeFileResult>(info.This())->GetValue()->automergeable;
 // start convert_to_v8 block
     to = Nan::New<Number>( automergeable);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitMergeFileResult::Path) {
      Local<v8::Value> to;

       const char *
         path =
         Nan::ObjectWrap::Unwrap<GitMergeFileResult>(info.This())->GetValue()->path;
 // start convert_to_v8 block
  if (path){
       to = Nan::New<String>(path).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitMergeFileResult::Mode) {
      Local<v8::Value> to;

       unsigned int
         mode =
         Nan::ObjectWrap::Unwrap<GitMergeFileResult>(info.This())->GetValue()->mode;
 // start convert_to_v8 block
     to = Nan::New<Number>( mode);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitMergeFileResult::Ptr) {
      Local<v8::Value> to;

       const char *
         ptr =
         Nan::ObjectWrap::Unwrap<GitMergeFileResult>(info.This())->GetValue()->ptr;
 // start convert_to_v8 block
  if (ptr){
       to = Nan::New<String>(ptr).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitMergeFileResult::Len) {
      Local<v8::Value> to;

       size_t
         len =
         Nan::ObjectWrap::Unwrap<GitMergeFileResult>(info.This())->GetValue()->len;
 // start convert_to_v8 block
     to = Nan::New<Number>( len);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
    Nan::Persistent<Function> GitMergeFileResult::constructor_template;
 