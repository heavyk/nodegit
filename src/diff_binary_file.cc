// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/diff_binary_file.h"
#include "../include/functions/sleep_for_ms.h"

 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitDiffBinaryFile::GitDiffBinaryFile(git_diff_binary_file *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitDiffBinaryFile::~GitDiffBinaryFile() {
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
   }

  void GitDiffBinaryFile::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("DiffBinaryFile").ToLocalChecked());

         Nan::SetPrototypeMethod(tpl, "type", Type);
         Nan::SetPrototypeMethod(tpl, "data", Data);
         Nan::SetPrototypeMethod(tpl, "datalen", Datalen);
         Nan::SetPrototypeMethod(tpl, "inflatedlen", Inflatedlen);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("DiffBinaryFile").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitDiffBinaryFile::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitDiffBinaryFile cannot be instantiated.");
     }

    GitDiffBinaryFile* object = new GitDiffBinaryFile(static_cast<git_diff_binary_file *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitDiffBinaryFile::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitDiffBinaryFile::constructor_template), 2, argv).ToLocalChecked());
  }

  git_diff_binary_file *GitDiffBinaryFile::GetValue() {
    return this->raw;
  }

  git_diff_binary_file **GitDiffBinaryFile::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitDiffBinaryFile::ClearValue() {
    this->raw = NULL;
  }

      NAN_METHOD(GitDiffBinaryFile::Type) {
      Local<v8::Value> to;

       git_diff_binary_t
         type =
         Nan::ObjectWrap::Unwrap<GitDiffBinaryFile>(info.This())->GetValue()->type;
 // start convert_to_v8 block
     to = Nan::New<Number>( type);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDiffBinaryFile::Data) {
      Local<v8::Value> to;

       const char *
         data =
         Nan::ObjectWrap::Unwrap<GitDiffBinaryFile>(info.This())->GetValue()->data;
 // start convert_to_v8 block
  if (data){
       to = Nan::New<String>(data).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDiffBinaryFile::Datalen) {
      Local<v8::Value> to;

       size_t
         datalen =
         Nan::ObjectWrap::Unwrap<GitDiffBinaryFile>(info.This())->GetValue()->datalen;
 // start convert_to_v8 block
     to = Nan::New<Number>( datalen);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitDiffBinaryFile::Inflatedlen) {
      Local<v8::Value> to;

       size_t
         inflatedlen =
         Nan::ObjectWrap::Unwrap<GitDiffBinaryFile>(info.This())->GetValue()->inflatedlen;
 // start convert_to_v8 block
     to = Nan::New<Number>( inflatedlen);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
    Nan::Persistent<Function> GitDiffBinaryFile::constructor_template;
 