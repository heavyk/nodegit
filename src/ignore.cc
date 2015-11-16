// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/ignore.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/repository.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

 
  void GitIgnore::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<Object> object = Nan::New<Object>();

        Nan::SetMethod(object, "addRule", AddRule);
         Nan::SetMethod(object, "clearInternalRules", ClearInternalRules);
         Nan::SetMethod(object, "pathIsIgnored", PathIsIgnored);
  
    Nan::Set(target, Nan::New<String>("Ignore").ToLocalChecked(), object);
  }

  
/*
 * @param Repository repo
   * @param String rules
     * @return Number  result    */
NAN_METHOD(GitIgnore::AddRule) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String rules is required.");
  }

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_rules;

  String::Utf8Value rules(info[1]->ToString());
  from_rules = (const char *) strdup(*rules);
// end convert_from_v8 block
   int result = git_ignore_add_rule(
from_repo
,from_rules
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
 * @param Repository repo
     * @return Number  result    */
NAN_METHOD(GitIgnore::ClearInternalRules) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
   int result = git_ignore_clear_internal_rules(
from_repo
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
  * @param Repository repo
   * @param String path
     * @return Number ignored    */
NAN_METHOD(GitIgnore::PathIsIgnored) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String path is required.");
  }

  int ignored = 0;
// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_path;

  String::Utf8Value path(info[1]->ToString());
  from_path = (const char *) strdup(*path);
// end convert_from_v8 block
   int result = git_ignore_path_is_ignored(
&ignored
,from_repo
,from_path
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( ignored);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
      Nan::Persistent<Function> GitIgnore::constructor_template;
 