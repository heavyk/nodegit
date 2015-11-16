// This is a generated file, modify: generate/templates/class_content.cc.
#include <nan.h>
#include <string.h>

extern "C" {
  #include <git2.h>
 }

#include "../include/functions/copy.h"
#include "../include/revwalk.h"
#include "../include/functions/sleep_for_ms.h"

  #include "../include/oid.h"
  #include "../include/repository.h"
 
#include <iostream>

using namespace std;
using namespace v8;
using namespace node;

  GitRevwalk::GitRevwalk(git_revwalk *raw, bool selfFreeing) {
    this->raw = raw;
    this->selfFreeing = selfFreeing;
  }

  GitRevwalk::~GitRevwalk() {
      if (this->selfFreeing) {
        git_revwalk_free(this->raw);
        this->raw = NULL;
      }
 
    // this will cause an error if you have a non-self-freeing object that also needs
    // to save values. Since the object that will eventually free the object has no
    // way of knowing to free these values.
                                                          }

  void GitRevwalk::InitializeComponent(Local<v8::Object> target) {
    Nan::HandleScope scope;

    Local<FunctionTemplate> tpl = Nan::New<FunctionTemplate>(JSNewFunction);

    tpl->InstanceTemplate()->SetInternalFieldCount(1);
    tpl->SetClassName(Nan::New("Revwalk").ToLocalChecked());

          Nan::SetPrototypeMethod(tpl, "hide", Hide);
            Nan::SetPrototypeMethod(tpl, "hideGlob", HideGlob);
            Nan::SetPrototypeMethod(tpl, "hideHead", HideHead);
            Nan::SetPrototypeMethod(tpl, "hideRef", HideRef);
             Nan::SetMethod(tpl, "create", Create);
            Nan::SetPrototypeMethod(tpl, "next", Next);
            Nan::SetPrototypeMethod(tpl, "push", Push);
            Nan::SetPrototypeMethod(tpl, "pushGlob", PushGlob);
            Nan::SetPrototypeMethod(tpl, "pushHead", PushHead);
            Nan::SetPrototypeMethod(tpl, "pushRange", PushRange);
            Nan::SetPrototypeMethod(tpl, "pushRef", PushRef);
            Nan::SetPrototypeMethod(tpl, "repository", Repository);
            Nan::SetPrototypeMethod(tpl, "reset", Reset);
            Nan::SetPrototypeMethod(tpl, "simplifyFirstParent", SimplifyFirstParent);
            Nan::SetPrototypeMethod(tpl, "sorting", Sorting);
    
    Local<Function> _constructor_template = Nan::GetFunction(tpl).ToLocalChecked();
    constructor_template.Reset(_constructor_template);
    Nan::Set(target, Nan::New("Revwalk").ToLocalChecked(), _constructor_template);
  }

  NAN_METHOD(GitRevwalk::JSNewFunction) {

    if (info.Length() == 0 || !info[0]->IsExternal()) {
         return Nan::ThrowError("A new GitRevwalk cannot be instantiated.");
     }

    GitRevwalk* object = new GitRevwalk(static_cast<git_revwalk *>(Local<External>::Cast(info[0])->Value()), Nan::To<bool>(info[1]).FromJust());
    object->Wrap(info.This());

    info.GetReturnValue().Set(info.This());
  }

  Local<v8::Value> GitRevwalk::New(void *raw, bool selfFreeing) {
    Nan::EscapableHandleScope scope;
    Local<v8::Value> argv[2] = { Nan::New<External>((void *)raw), Nan::New(selfFreeing) };
    return scope.Escape(Nan::NewInstance(Nan::New(GitRevwalk::constructor_template), 2, argv).ToLocalChecked());
  }

  git_revwalk *GitRevwalk::GetValue() {
    return this->raw;
  }

  git_revwalk **GitRevwalk::GetRefValue() {
    return this->raw == NULL ? NULL : &this->raw;
  }

  void GitRevwalk::ClearValue() {
    this->raw = NULL;
  }

  
/*
   * @param Oid commit_id
     * @return Number  result    */
NAN_METHOD(GitRevwalk::Hide) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0
    || (!info[0]->IsObject() && !info[0]->IsString())) {
    return Nan::ThrowError("Oid commit_id is required.");
  }
// start convert_from_v8 block
  const git_oid * from_commit_id;
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

    from_commit_id = oidOut;
  }
  else {
    from_commit_id = Nan::ObjectWrap::Unwrap<GitOid>(info[0]->ToObject())->GetValue();
  }
// end convert_from_v8 block
   int result = git_revwalk_hide(
Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
,from_commit_id
  );

   if (info[0]->IsString()) {
    free((void *)from_commit_id);
  }

  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param String glob
     * @return Number  result    */
NAN_METHOD(GitRevwalk::HideGlob) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String glob is required.");
  }

// start convert_from_v8 block
  const char * from_glob;

  String::Utf8Value glob(info[0]->ToString());
  from_glob = (const char *) strdup(*glob);
// end convert_from_v8 block
   int result = git_revwalk_hide_glob(
Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
,from_glob
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitRevwalk::HideHead) {
  Nan::EscapableHandleScope scope;

   int result = git_revwalk_hide_head(
Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param String refname
     * @return Number  result    */
NAN_METHOD(GitRevwalk::HideRef) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String refname is required.");
  }

// start convert_from_v8 block
  const char * from_refname;

  String::Utf8Value refname(info[0]->ToString());
  from_refname = (const char *) strdup(*refname);
// end convert_from_v8 block
   int result = git_revwalk_hide_ref(
Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
,from_refname
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
  * @param Repository repo
     * @return Revwalk out    */
NAN_METHOD(GitRevwalk::Create) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsObject()) {
    return Nan::ThrowError("Repository repo is required.");
  }

  git_revwalk * out = 0;
// start convert_from_v8 block
  git_repository * from_repo;
  from_repo = Nan::ObjectWrap::Unwrap<GitRepository>(info[0]->ToObject())->GetValue();
// end convert_from_v8 block
 git_revwalk_new(
&out
,from_repo
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (out != NULL) {
    // GitRevwalk out
       to = GitRevwalk::New((void *)out, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
  
/*
     * @param Oid callback
   */
NAN_METHOD(GitRevwalk::Next) {

  if (info.Length() == 0 || !info[0]->IsFunction()) {
    return Nan::ThrowError("Callback is required and must be a Function.");
  }

  NextBaton* baton = new NextBaton;

  baton->error_code = GIT_OK;
  baton->error = NULL;

  baton->out = (git_oid *)malloc(sizeof(git_oid ));
  baton->walk = Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue();

  Nan::Callback *callback = new Nan::Callback(Local<Function>::Cast(info[0]));
  NextWorker *worker = new NextWorker(baton, callback);
  worker->SaveToPersistent("walk", info.This());

  Nan::AsyncQueueWorker(worker);
  return;
}

void GitRevwalk::NextWorker::Execute() {
  int result = git_revwalk_next(
baton->out,baton->walk    );

  baton->error_code = result;

  if (result != GIT_OK && giterr_last() != NULL) {
    baton->error = git_error_dup(giterr_last());
  }

}

void GitRevwalk::NextWorker::HandleOKCallback() {
  if (baton->error_code == GIT_OK) {
    Local<v8::Value> to;
// start convert_to_v8 block
  
  if (baton->out != NULL) {
    // GitOid baton->out
       to = GitOid::New((void *)baton->out, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
    Local<v8::Value> result = to;
    Local<v8::Value> argv[2] = {
      Nan::Null(),
      result
    };
    callback->Call(2, argv);
  } else {
    if (baton->error) {
      Local<v8::Value> argv[1] = {
        Nan::Error(baton->error->message)
      };
      callback->Call(1, argv);
      if (baton->error->message)
        free((void *)baton->error->message);
      free((void *)baton->error);
    } else if (baton->error_code < 0) {
      std::queue< Local<v8::Value> > workerArguments;
      bool callbackFired = false;
      while(!workerArguments.empty()) {
        Local<v8::Value> node = workerArguments.front();
        workerArguments.pop();

        if (
          !node->IsObject()
          || node->IsArray()
          || node->IsBooleanObject()
          || node->IsDate()
          || node->IsFunction()
          || node->IsNumberObject()
          || node->IsRegExp()
          || node->IsStringObject()
        ) {
          continue;
        }

        Local<v8::Object> nodeObj = node->ToObject();
        Local<v8::Value> checkValue = nodeObj->GetHiddenValue(Nan::New("NodeGitPromiseError").ToLocalChecked());

        if (!checkValue.IsEmpty() && !checkValue->IsNull() && !checkValue->IsUndefined()) {
          Local<v8::Value> argv[1] = {
            checkValue->ToObject()
          };
          callback->Call(1, argv);
          callbackFired = true;
          break;
        }

        Local<v8::Array> properties = nodeObj->GetPropertyNames();
        for (unsigned int propIndex = 0; propIndex < properties->Length(); ++propIndex) {
          Local<v8::String> propName = properties->Get(propIndex)->ToString();
          Local<v8::Value> nodeToQueue = nodeObj->Get(propName);
          if (!nodeToQueue->IsUndefined()) {
            workerArguments.push(nodeToQueue);
          }
        }
      }

      if (!callbackFired) {
        Local<v8::Object> err = Nan::Error("Method next has thrown an error.")->ToObject();
        err->Set(Nan::New("errno").ToLocalChecked(), Nan::New(baton->error_code));
        Local<v8::Value> argv[1] = {
          err
        };
        callback->Call(1, argv);
      }
    } else {
      callback->Call(0, NULL);
    }

  }


  delete baton;
}

   
/*
   * @param Oid id
     * @return Number  result    */
NAN_METHOD(GitRevwalk::Push) {
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
   int result = git_revwalk_push(
Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
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
   * @param String glob
     * @return Number  result    */
NAN_METHOD(GitRevwalk::PushGlob) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String glob is required.");
  }

// start convert_from_v8 block
  const char * from_glob;

  String::Utf8Value glob(info[0]->ToString());
  from_glob = (const char *) strdup(*glob);
// end convert_from_v8 block
   int result = git_revwalk_push_glob(
Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
,from_glob
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Number  result    */
NAN_METHOD(GitRevwalk::PushHead) {
  Nan::EscapableHandleScope scope;

   int result = git_revwalk_push_head(
Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param String range
     * @return Number  result    */
NAN_METHOD(GitRevwalk::PushRange) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String range is required.");
  }

// start convert_from_v8 block
  const char * from_range;

  String::Utf8Value range(info[0]->ToString());
  from_range = (const char *) strdup(*range);
// end convert_from_v8 block
   int result = git_revwalk_push_range(
Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
,from_range
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
   * @param String refname
     * @return Number  result    */
NAN_METHOD(GitRevwalk::PushRef) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsString()) {
    return Nan::ThrowError("String refname is required.");
  }

// start convert_from_v8 block
  const char * from_refname;

  String::Utf8Value refname(info[0]->ToString());
  from_refname = (const char *) strdup(*refname);
// end convert_from_v8 block
   int result = git_revwalk_push_ref(
Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
,from_refname
  );

 
  Local<v8::Value> to;
// start convert_to_v8 block
     to = Nan::New<Number>( result);
  // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     * @return Repository  result    */
NAN_METHOD(GitRevwalk::Repository) {
  Nan::EscapableHandleScope scope;

   git_repository * result = git_revwalk_repository(
Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
  );

   // null checks on pointers
  if (!result) {
    return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
  }

  Local<v8::Value> to;
// start convert_to_v8 block
  
  if (result != NULL) {
    // GitRepository result
       to = GitRepository::New((void *)result, false);
   }
  else {
    to = Nan::Null();
  }

 // end convert_to_v8 block
  return info.GetReturnValue().Set(scope.Escape(to));
}
   
/*
     */
NAN_METHOD(GitRevwalk::Reset) {
  Nan::EscapableHandleScope scope;

 git_revwalk_reset(
Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
  );

   return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
}
   
/*
     */
NAN_METHOD(GitRevwalk::SimplifyFirstParent) {
  Nan::EscapableHandleScope scope;

 git_revwalk_simplify_first_parent(
Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
  );

   return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
}
   
/*
   * @param Number sort_mode
     */
NAN_METHOD(GitRevwalk::Sorting) {
  Nan::EscapableHandleScope scope;

  if (info.Length() == 0 || !info[0]->IsNumber()) {
    return Nan::ThrowError("Number sort_mode is required.");
  }

// start convert_from_v8 block
  unsigned int from_sort_mode;
  from_sort_mode = (unsigned int)   info[0]->ToNumber()->Value();
// end convert_from_v8 block
 git_revwalk_sorting(
Nan::ObjectWrap::Unwrap<GitRevwalk>(info.This())->GetValue()
,from_sort_mode
  );

   return info.GetReturnValue().Set(scope.Escape(Nan::Undefined()));
}
      Nan::Persistent<Function> GitRevwalk::constructor_template;
 