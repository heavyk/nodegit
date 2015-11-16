// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/diff_binary.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/diff_binary_file.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitDiffBinary::GitDiffBinary(git_diff_binary *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitDiffBinary::~GitDiffBinary() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitDiffBinary::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("DiffBinary").ToLocalChecked());

         Nan::SetPrototypeMethod(tpl, "oldFile", OldFile);
         Nan::SetPrototypeMethod(tpl, "newFile", NewFile);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("DiffBinary").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitDiffBinary::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitDiffBinary cannot be instantiated.");
     }

    GitDiffBinary* object = new GitDiffBinary(static_cast<git_diff_binary *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitDiffBinary::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitDiffBinary::constructor_template), 2, argv).ToLocalChecked());
  }

  git_diff_binary *GitDiffBinary::GetValue() {
    return this->raw;
  }

  git_diff_binary **GitDiffBinary::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitDiffBinary::ClearValue() {
    this->raw = NULL;
  }

      NAN_METHOD(GitDiffBinary::OldFile) {
      Local<v8::Value> to;

       git_diff_binary_file
        *
          old_file =
        &
          Nan::ObjectWrap::Unwrap<GitDiffBinary>(info.This())->GetValue()->old_file;
 // start convert_to_v8 block
  
  if (old_file != NULL) {
    // GitDiffBinaryFile old_file
       to = GitDiffBinaryFile::New((void *)old_file, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDiffBinary::NewFile) {
      Local<v8::Value> to;

       git_diff_binary_file
        *
          new_file =
        &
          Nan::ObjectWrap::Unwrap<GitDiffBinary>(info.This())->GetValue()->new_file;
 // start convert_to_v8 block
  
  if (new_file != NULL) {
    // GitDiffBinaryFile new_file
       to = GitDiffBinaryFile::New((void *)new_file, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
    Nan::Persistent<Function> GitDiffBinary::constructor_template;
 