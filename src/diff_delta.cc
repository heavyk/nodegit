// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/diff_delta.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/diff_file.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitDiffDelta::GitDiffDelta(git_diff_delta *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitDiffDelta::~GitDiffDelta() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitDiffDelta::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("DiffDelta").ToLocalChecked());

         Nan::SetPrototypeMethod(tpl, "status", Status);
         Nan::SetPrototypeMethod(tpl, "flags", Flags);
         Nan::SetPrototypeMethod(tpl, "similarity", Similarity);
         Nan::SetPrototypeMethod(tpl, "nfiles", Nfiles);
         Nan::SetPrototypeMethod(tpl, "oldFile", OldFile);
         Nan::SetPrototypeMethod(tpl, "newFile", NewFile);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("DiffDelta").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitDiffDelta::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitDiffDelta cannot be instantiated.");
     }

    GitDiffDelta* object = new GitDiffDelta(static_cast<git_diff_delta *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitDiffDelta::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitDiffDelta::constructor_template), 2, argv).ToLocalChecked());
  }

  git_diff_delta *GitDiffDelta::GetValue() {
    return this->raw;
  }

  git_diff_delta **GitDiffDelta::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitDiffDelta::ClearValue() {
    this->raw = NULL;
  }

      NAN_METHOD(GitDiffDelta::Status) {
      Local<v8::Value> to;

       git_delta_t
         status =
         Nan::ObjectWrap::Unwrap<GitDiffDelta>(info.This())->GetValue()->status;
 // start convert_to_v8 block
     to = Nan::New<Number>( status);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDiffDelta::Flags) {
      Local<v8::Value> to;

       uint32_t
         flags =
         Nan::ObjectWrap::Unwrap<GitDiffDelta>(info.This())->GetValue()->flags;
 // start convert_to_v8 block
     to = Nan::New<Number>( flags);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDiffDelta::Similarity) {
      Local<v8::Value> to;

       uint16_t
         similarity =
         Nan::ObjectWrap::Unwrap<GitDiffDelta>(info.This())->GetValue()->similarity;
 // start convert_to_v8 block
     to = Nan::New<Number>( similarity);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDiffDelta::Nfiles) {
      Local<v8::Value> to;

       uint16_t
         nfiles =
         Nan::ObjectWrap::Unwrap<GitDiffDelta>(info.This())->GetValue()->nfiles;
 // start convert_to_v8 block
     to = Nan::New<Number>( nfiles);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDiffDelta::OldFile) {
      Local<v8::Value> to;

       git_diff_file
        *
          old_file =
        &
          Nan::ObjectWrap::Unwrap<GitDiffDelta>(info.This())->GetValue()->old_file;
 // start convert_to_v8 block
  
  if (old_file != NULL) {
    // GitDiffFile old_file
       to = GitDiffFile::New((void *)old_file, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDiffDelta::NewFile) {
      Local<v8::Value> to;

       git_diff_file
        *
          new_file =
        &
          Nan::ObjectWrap::Unwrap<GitDiffDelta>(info.This())->GetValue()->new_file;
 // start convert_to_v8 block
  
  if (new_file != NULL) {
    // GitDiffFile new_file
       to = GitDiffFile::New((void *)new_file, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
    Nan::Persistent<Function> GitDiffDelta::constructor_template;
 