// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/diff_line.h"
#include "../include/functions/sleep_for_ms.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitDiffLine::GitDiffLine(git_diff_line *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitDiffLine::~GitDiffLine() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitDiffLine::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("DiffLine").ToLocalChecked());

         Nan::SetPrototypeMethod(tpl, "origin", Origin);
         Nan::SetPrototypeMethod(tpl, "oldLineno", OldLineno);
         Nan::SetPrototypeMethod(tpl, "newLineno", NewLineno);
         Nan::SetPrototypeMethod(tpl, "numLines", NumLines);
         Nan::SetPrototypeMethod(tpl, "contentLen", ContentLen);
         Nan::SetPrototypeMethod(tpl, "contentOffset", ContentOffset);
         Nan::SetPrototypeMethod(tpl, "content", Content);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("DiffLine").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitDiffLine::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitDiffLine cannot be instantiated.");
     }

    GitDiffLine* object = new GitDiffLine(static_cast<git_diff_line *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitDiffLine::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitDiffLine::constructor_template), 2, argv).ToLocalChecked());
  }

  git_diff_line *GitDiffLine::GetValue() {
    return this->raw;
  }

  git_diff_line **GitDiffLine::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitDiffLine::ClearValue() {
    this->raw = NULL;
  }

      NAN_METHOD(GitDiffLine::Origin) {
      Local<v8::Value> to;

       int
         origin =
         Nan::ObjectWrap::Unwrap<GitDiffLine>(info.This())->GetValue()->origin;
 // start convert_to_v8 block
     to = Nan::New<Number>( origin);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDiffLine::OldLineno) {
      Local<v8::Value> to;

       int
         old_lineno =
         Nan::ObjectWrap::Unwrap<GitDiffLine>(info.This())->GetValue()->old_lineno;
 // start convert_to_v8 block
     to = Nan::New<Number>( old_lineno);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDiffLine::NewLineno) {
      Local<v8::Value> to;

       int
         new_lineno =
         Nan::ObjectWrap::Unwrap<GitDiffLine>(info.This())->GetValue()->new_lineno;
 // start convert_to_v8 block
     to = Nan::New<Number>( new_lineno);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDiffLine::NumLines) {
      Local<v8::Value> to;

       int
         num_lines =
         Nan::ObjectWrap::Unwrap<GitDiffLine>(info.This())->GetValue()->num_lines;
 // start convert_to_v8 block
     to = Nan::New<Number>( num_lines);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDiffLine::ContentLen) {
      Local<v8::Value> to;

       size_t
         content_len =
         Nan::ObjectWrap::Unwrap<GitDiffLine>(info.This())->GetValue()->content_len;
 // start convert_to_v8 block
     to = Nan::New<Number>( content_len);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDiffLine::ContentOffset) {
      Local<v8::Value> to;

       git_off_t
         content_offset =
         Nan::ObjectWrap::Unwrap<GitDiffLine>(info.This())->GetValue()->content_offset;
 // start convert_to_v8 block
     to = Nan::New<Number>( content_offset);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDiffLine::Content) {
      Local<v8::Value> to;

       const char *
         content =
         Nan::ObjectWrap::Unwrap<GitDiffLine>(info.This())->GetValue()->content;
 // start convert_to_v8 block
  if (content){
       to = Nan::New<String>(content).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
    Nan::Persistent<Function> GitDiffLine::constructor_template;
 