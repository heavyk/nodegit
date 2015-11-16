// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/packbuilder.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/oid.h"
  #include "../include/revwalk.h"
  #include "../include/repository.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitPackbuilder::GitPackbuilder(git_packbuilder *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitPackbuilder::~GitPackbuilder() {
      if (this->selfFreeing) {
        git_packbuilder_free(this->raw);
        this->raw = NULL;
      }
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                             }

  void GitPackbuilder::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Packbuilder").ToLocalChecked());

          Nan::SetPrototypeMethod(tpl, "free", Free);
            Nan::SetPrototypeMethod(tpl, "hash", Hash);
            Nan::SetPrototypeMethod(tpl, "insert", Insert);
            Nan::SetPrototypeMethod(tpl, "insertCommit", InsertCommit);
            Nan::SetPrototypeMethod(tpl, "insertRecur", InsertRecur);
            Nan::SetPrototypeMethod(tpl, "insertTree", InsertTree);
            Nan::SetPrototypeMethod(tpl, "insertWalk", InsertWalk);
             Nan::SetMethod(tpl, "create", Create);
            Nan::SetPrototypeMethod(tpl, "objectCount", ObjectCount);
            Nan::SetPrototypeMethod(tpl, "setThreads", SetThreads);
            Nan::SetPrototypeMethod(tpl, "written", Written);
    
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Packbuilder").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitPackbuilder::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitPackbuilder cannot be instantiated.");
     }

    GitPackbuilder* object = new GitPackbuilder(static_cast<git_packbuilder *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitPackbuilder::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitPackbuilder::constructor_template), 2, argv).ToLocalChecked());
  }

  git_packbuilder *GitPackbuilder::GetValue() {
    return this->raw;
  }

  git_packbuilder **GitPackbuilder::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitPackbuilder::ClearValue() {
    this->raw = NULL;
  }

  
/*
     */
NAN_METHOD(GitPackbuilder::Free) {
  Nan::EscapableHandleScope scope;

if (Nan::ObjectWrap::Unwrap<GitPackbuilder>(info.This())->GetValue() != NULL) {
 git_packbuilder_free(
Nan::ObjectWrap::Unwrap<GitPackbuilder>(info.This())->GetValue()
  );

  Nan::ObjectWrap::Unwrap<GitPackbuilder>(info.This())->ClearValue();
}
   return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
}
   
/*
     * @return Oid  result    */
NAN_METHOD(GitPackbuilder::Hash) {
  Nan::EscapableHandleScope scope;

   const git_oid * result = git_packbuilder_hash(
Nan::ObjectWrap::Unwrap<GitPackbuilder>(info.This())->GetValue()
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitOid result
       to = GitOid::New((void *)result, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param Oid id
   * @param String name
     * @return Number  result    */
NAN_METHOD(GitPackbuilder::Insert) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0
    || (!info[0]->IsObject() && !info[0]->IsString())) {
    return Nan::ThrowError("Oid id is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String name is required.");
  }

// start convert_from_v8 block
  const git_oid * from_id;
  if (info[0]->IsString()) {
    // Try and parse in a string to a git_oid
    String::Utf8Value oidString(info[0]->ToString());
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(*oidString)) != GIT_OK) {
      free(oidOut);

      if (giterr_last()) {
        return Nan::ThrowError(giterr_last()->message);
      } else {
        return Nan::ThrowError("Unknown Error");
      }
    }

    from_id = oidOut;
  }
  else {
    from_id = Nan::ObjectWrap::Unwrap<GitOid>(info[0]->ToObject())->GetValue();
  }
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_name;

  String::Utf8Value name(info[1]->ToString());
  from_name = (const char *) strdup(*name);
// end convert_from_v8 block
   int result = git_packbuilder_insert(
Nan::ObjectWrap::Unwrap<GitPackbuilder>(info.This())->GetValue()
,from_id
,from_name
  );

   if (info[0]->IsString()) {
    free((void *)from_id);
  }

  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param Oid id
     * @return Number  result    */
NAN_METHOD(GitPackbuilder::InsertCommit) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0
    || (!info[0]->IsObject() && !info[0]->IsString())) {
    return Nan::ThrowError("Oid id is required.");
  }
// start convert_from_v8 block
  const git_oid * from_id;
  if (info[0]->IsString()) {
    // Try and parse in a string to a git_oid
    String::Utf8Value oidString(info[0]->ToString());
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(*oidString)) != GIT_OK) {
      free(oidOut);

      if (giterr_last()) {
        return Nan::ThrowError(giterr_last()->message);
      } else {
        return Nan::ThrowError("Unknown Error");
      }
    }

    from_id = oidOut;
  }
  else {
    from_id = Nan::ObjectWrap::Unwrap<GitOid>(info[0]->ToObject())->GetValue();
  }
// end convert_from_v8 block
   int result = git_packbuilder_insert_commit(
Nan::ObjectWrap::Unwrap<GitPackbuilder>(info.This())->GetValue()
,from_id
  );

   if (info[0]->IsString()) {
    free((void *)from_id);
  }

  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param Oid id
   * @param String name
     * @return Number  result    */
NAN_METHOD(GitPackbuilder::InsertRecur) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0
    || (!info[0]->IsObject() && !info[0]->IsString())) {
    return Nan::ThrowError("Oid id is required.");
  }
  if (info.Length() == 1 || !info[1]->IsString()) {
    return Nan::ThrowError("String name is required.");
  }

// start convert_from_v8 block
  const git_oid * from_id;
  if (info[0]->IsString()) {
    // Try and parse in a string to a git_oid
    String::Utf8Value oidString(info[0]->ToString());
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(*oidString)) != GIT_OK) {
      free(oidOut);

      if (giterr_last()) {
        return Nan::ThrowError(giterr_last()->message);
      } else {
        return Nan::ThrowError("Unknown Error");
      }
    }

    from_id = oidOut;
  }
  else {
    from_id = Nan::ObjectWrap::Unwrap<GitOid>(info[0]->ToObject())->GetValue();
  }
// end convert_from_v8 block
// start convert_from_v8 block
  const char * from_name;

  String::Utf8Value name(info[1]->ToString());
  from_name = (const char *) strdup(*name);
// end convert_from_v8 block
   int result = git_packbuilder_insert_recur(
Nan::ObjectWrap::Unwrap<GitPackbuilder>(info.This())->GetValue()
,from_id
,from_name
  );

   if (info[0]->IsString()) {
    free((void *)from_id);
  }

  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param Oid id
     * @return Number  result    */
NAN_METHOD(GitPackbuilder::InsertTree) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0
    || (!info[0]->IsObject() && !info[0]->IsString())) {
    return Nan::ThrowError("Oid id is required.");
  }
// start convert_from_v8 block
  const git_oid * from_id;
  if (info[0]->IsString()) {
    // Try and parse in a string to a git_oid
    String::Utf8Value oidString(info[0]->ToString());
    git_oid *oidOut = (git_oid *)malloc(sizeof(git_oid));

    if (git_oid_fromstr(oidOut, (const char *) strdup(*oidString)) != GIT_OK) {
      free(oidOut);

      if (giterr_last()) {
        return Nan::ThrowError(giterr_last()->message);
      } else {
        return Nan::ThrowError("Unknown Error");
      }
    }

    from_id = oidOut;
  }
  else {
    from_id = Nan::ObjectWrap::Unwrap<GitOid>(info[0]->ToObject())->GetValue();
  }
// end convert_from_v8 block
   int result = git_packbuilder_insert_tree(
Nan::ObjectWrap::Unwrap<GitPackbuilder>(info.This())->GetValue()
,from_id
  );

   if (info[0]->IsString()) {
    free((void *)from_id);
  }

  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param Revwalk walk
     * @return Number  result    */
NAN_METHOD(GitPackbuilder::InsertWalk) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Revwalk walk is required.");
  }

// start convert_from_v8 block
  git_revwalk * from_walk;
  from_walk = Nan::ObjectWrap::Unwrap<GitRevwalk>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
   int result = git_packbuilder_insert_walk(
Nan::ObjectWrap::Unwrap<GitPackbuilder>(info.This())->GetValue()
,from_walk
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
  * @param Repository repo
     * @return Packbuilder out    */
NAN_METHOD(GitPackbuilder::Create) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  git_packbuilder * out = 0;
// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
 git_packbuilder_new(
&out
,from_repo
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (out != NULL) {
    // GitPackbuilder out
       to = GitPackbuilder::New((void *)out, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitPackbuilder::ObjectCount) {
  Nan::EscapableHandleScope scope;

   uint32_t result = git_packbuilder_object_count(
Nan::ObjectWrap::Unwrap<GitPackbuilder>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param Number n
     * @return Number  result    */
NAN_METHOD(GitPackbuilder::SetThreads) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number n is required.");
  }

// start convert_from_v8 block
  unsigned int from_n;
  from_n = (unsigned int)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
   unsigned int result = git_packbuilder_set_threads(
Nan::ObjectWrap::Unwrap<GitPackbuilder>(info.This())->GetValue()
,from_n
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitPackbuilder::Written) {
  Nan::EscapableHandleScope scope;

   uint32_t result = git_packbuilder_written(
Nan::ObjectWrap::Unwrap<GitPackbuilder>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
      Nan::Persistent<Function> GitPackbuilder::constructor_template;
 