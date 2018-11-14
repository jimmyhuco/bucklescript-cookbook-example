/* Using a built-in OCaml error */
let notFoundPromise =
  Js.Promise.make((~resolve as _, ~reject) => reject(. Not_found));

let _: Js.Promise.t(unit) =
  notFoundPromise
  |> Js.Promise.then_(value => Js.Promise.resolve(Js.log(value)))
  |> Js.Promise.catch(err => Js.Promise.resolve(Js.log(err)));

/* Using a custom error */
exception Oh_no(string);

let ohNoPromise: Js.Promise.t(_) =
  Js.Promise.make((~resolve as _, ~reject) => reject(. Oh_no("oh no")));

let _: Js.Promise.t(unit) =
  ohNoPromise |> Js.Promise.catch(err => Js.Promise.resolve(Js.log(err)));

/**
 * Unfortunately, as one can see - catch expects a very generic `Js.Promise.error` value
 * that doesn't give us much to do with.
 * In general, we should not rely on rejecting/catching errors for control flow;
 * it's much better to use a `result` type instead.
 */

let betterOk: Js.Promise.t(Belt.Result.t(string, _)) =
  Js.Promise.make((~resolve, ~reject as _) =>
    resolve(. Belt.Result.Ok("everything's fine"))
  );

let betterOhNo: Js.Promise.t(Belt.Result.t(_, string)) =
  Js.Promise.make((~resolve, ~reject as _) =>
    resolve(. Belt.Result.Error("nope nope nope"))
  );

let handleResult =
  Js.Promise.then_(result =>
    Js.Promise.resolve(
      switch (result) {
      | Belt.Result.Ok(text) => Js.log("OK: " ++ text)
      | Belt.Result.Error(reason) => Js.log("Oh no: " ++ reason)
      },
    )
  );

let _: Js.Promise.t(unit) = handleResult(betterOk);

let _: Js.Promise.t(unit) = handleResult(betterOhNo);