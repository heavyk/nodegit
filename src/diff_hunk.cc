// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/diff_hunk.h"
#include "../include/functions/sleep_for_ms.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitDiffHunk::GitDiffHunk(git_diff_hunk *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitDiffHunk::~GitDiffHunk() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitDiffHunk::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("DiffHunk").ToLocalChecked());

         Nan::SetPrototypeMethod(tpl, "oldStart", OldStart);
         Nan::SetPrototypeMethod(tpl, "oldLines", OldLines);
         Nan::SetPrototypeMethod(tpl, "newStart", NewStart);
         Nan::SetPrototypeMethod(tpl, "newLines", NewLines);
         Nan::SetPrototypeMethod(tpl, "headerLen", HeaderLen);
         Nan::SetPrototypeMethod(tpl, "header", Header);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("DiffHunk").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitDiffHunk::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitDiffHunk cannot be instantiated.");
     }

    GitDiffHunk* object = new GitDiffHunk(static_cast<git_diff_hunk *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitDiffHunk::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitDiffHunk::constructor_template), 2, argv).ToLocalChecked());
  }

  git_diff_hunk *GitDiffHunk::GetValue() {
    return this->raw;
  }

  git_diff_hunk **GitDiffHunk::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitDiffHunk::ClearValue() {
    this->raw = NULL;
  }

      NAN_METHOD(GitDiffHunk::OldStart) {
      Local<v8::Value> to;

       int
         old_start =
         Nan::ObjectWrap::Unwrap<GitDiffHunk>(info.This())->GetValue()->old_start;
 // start convert_to_v8 block
     to = Nan::New<Number>( old_start);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDiffHunk::OldLines) {
      Local<v8::Value> to;

       int
         old_lines =
         Nan::ObjectWrap::Unwrap<GitDiffHunk>(info.This())->GetValue()->old_lines;
 // start convert_to_v8 block
     to = Nan::New<Number>( old_lines);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDiffHunk::NewStart) {
      Local<v8::Value> to;

       int
         new_start =
         Nan::ObjectWrap::Unwrap<GitDiffHunk>(info.This())->GetValue()->new_start;
 // start convert_to_v8 block
     to = Nan::New<Number>( new_start);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDiffHunk::NewLines) {
      Local<v8::Value> to;

       int
         new_lines =
         Nan::ObjectWrap::Unwrap<GitDiffHunk>(info.This())->GetValue()->new_lines;
 // start convert_to_v8 block
     to = Nan::New<Number>( new_lines);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDiffHunk::HeaderLen) {
      Local<v8::Value> to;

       size_t
         header_len =
         Nan::ObjectWrap::Unwrap<GitDiffHunk>(info.This())->GetValue()->header_len;
 // start convert_to_v8 block
     to = Nan::New<Number>( header_len);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDiffHunk::Header) {
      Local<v8::Value> to;

       char *
         header =
         Nan::ObjectWrap::Unwrap<GitDiffHunk>(info.This())->GetValue()->header;
 // start convert_to_v8 block
  if (header){
       to = Nan::New<String>(header).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
    Nan::Persistent<Function> GitDiffHunk::constructor_template;
 