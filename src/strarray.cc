// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/strarray.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/str_array_converter.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitStrarray::GitStrarray(git_strarray *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitStrarray::~GitStrarray() {
      if (this->selfFreeing) {
        git_strarray_free(this->raw);
        this->raw = NULL;
      }
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
          }

  void GitStrarray::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Strarray").ToLocalChecked());

          Nan::SetPrototypeMethod(tpl, "copy", Copy);
            Nan::SetPrototypeMethod(tpl, "free", Free);
           Nan::SetPrototypeMethod(tpl, "strings", Strings);
         Nan::SetPrototypeMethod(tpl, "count", Count);
  
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Strarray").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitStrarray::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitStrarray cannot be instantiated.");
     }

    GitStrarray* object = new GitStrarray(static_cast<git_strarray *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitStrarray::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitStrarray::constructor_template), 2, argv).ToLocalChecked());
  }

  git_strarray *GitStrarray::GetValue() {
    return this->raw;
  }

  git_strarray **GitStrarray::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitStrarray::ClearValue() {
    this->raw = NULL;
  }

  
/*
       * @return Number  result    */
NAN_METHOD(GitStrarray::Copy) {
  Nan::EscapableHandleScope scope;

   int result = git_strarray_copy(
Nan::ObjectWrap::Unwrap<GitStrarray>(info.This())->GetValue()
,Nan::ObjectWrap::Unwrap<GitStrarray>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     */
NAN_METHOD(GitStrarray::Free) {
  Nan::EscapableHandleScope scope;

if (Nan::ObjectWrap::Unwrap<GitStrarray>(info.This())->GetValue() != NULL) {
 git_strarray_free(
Nan::ObjectWrap::Unwrap<GitStrarray>(info.This())->GetValue()
  );

  Nan::ObjectWrap::Unwrap<GitStrarray>(info.This())->ClearValue();
}
   return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
}
       NAN_METHOD(GitStrarray::Strings) {
      Local<v8::Value> to;

       char **
         strings =
         Nan::ObjectWrap::Unwrap<GitStrarray>(info.This())->GetValue()->strings;
 // start convert_to_v8 block
  if (strings){
      to = Nan::New<String>(*strings).ToLocalChecked();
   }
  else {
    to = Nan::Null();
  }

  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
     NAN_METHOD(GitStrarray::Count) {
      Local<v8::Value> to;

       size_t
         count =
         Nan::ObjectWrap::Unwrap<GitStrarray>(info.This())->GetValue()->count;
 // start convert_to_v8 block
     to = Nan::New<Number>( count);
  // end convert_to_v8 block
      info.GetReturnValue().Set(to);
    }
    Nan::Persistent<Function> GitStrarray::constructor_template;
 