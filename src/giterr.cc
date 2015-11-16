// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/giterr.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/error.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

 
  void GitGiterr::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<Object> object = Nan::New<Object>();

        Nan::SetMethod(object, "errClear", GiterrClear);
         Nan::SetMethod(object, "errDetach", GiterrDetach);
         Nan::SetMethod(object, "errLast", GiterrLast);
         Nan::SetMethod(object, "errSetOom", GiterrSetOom);
         Nan::SetMethod(object, "errSetString", GiterrSetStr);
  
    Nan::Set(target, Nan::New<String>("Giterr").ToLocalChecked(), object);
  }

  
/*
   */
NAN_METHOD(GitGiterr::GiterrClear) {
  Nan::EscapableHandleScope scope;

 giterr_clear(
  );

   return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
}
   
/*
 * @param Error cpy
     * @return Number  result    */
NAN_METHOD(GitGiterr::GiterrDetach) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Error cpy is required.");
  }

// start convert_from_v8 block
  git_error * from_cpy;
  from_cpy = Nan::ObjectWrap::Unwrap<GitError>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
   int result = giterr_detach(
from_cpy
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @return Error  result    */
NAN_METHOD(GitGiterr::GiterrLast) {
  Nan::EscapableHandleScope scope;

   const git_error * result = giterr_last(
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitError result
       to = GitError::New((void *)result, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   */
NAN_METHOD(GitGiterr::GiterrSetOom) {
  Nan::EscapableHandleScope scope;

 giterr_set_oom(
  );

   return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
}
   
/*
 * @param Number error_class
   * @param String string
     */
NAN_METHOD(GitGiterr::GiterrSetStr) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number error_class is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String string is required.");
  }

// start convert_from_v8 block
  int from_error_class;
  from_error_class = (int)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_string;

  String::Utf8Value string(info[1]->ToString());
  from_string = (const char *) strdup(*string);
// end convert_from_v8 block
 giterr_set_str(
from_error_class
,from_string
  );

   return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
}
      Nan::Persistent<Function> GitGiterr::constructor_template;
 