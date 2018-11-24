let okPromise = Js.Promise.make((~resolve, ~reject as _) => resolve(. "ok"));

/* Simpler promise creation for static values */
let _: Js.Promise.t(string) = Js.Promise.resolve("easy");

/* Create a promise that resolves much later */
let _: Js.Promise.t(_) = Js.Promise.reject(Invalid_argument("too easy"));

let timer =
  Js.Promise.make((~resolve, ~reject as _) => {
    /* `Js.Global.setTimeout` returns a `timeoutId`, so we assign it to
       `_` to ginore and, and annotate its type to make sure we don't
       accidentally partially apply the function */
    let _: Js.Global.timeoutId =
      Js.Global.setTimeout(() => resolve(. "Done!"), 1000);
    ();
  });

/*
 * Note that we *have* to return a new promise inside of the callback given to then_;
 */
let _: Js.Promise.t(string) =
  Js.Promise.then_(value => Js.Promise.resolve(value), okPromise);

/* Chaining */
let _: Js.Promise.t(unit) =
  Js.Promise.then_(
    value => {
      Js.log(value);
      Js.Promise.resolve();
    },
    Js.Promise.then_(
      value => Js.Promise.resolve(value + 1),
      Js.Promise.resolve(1),
    ),
  );

/* Better with pipes 😉 */
let _: Js.Promise.t(int) =
  Js.Promise.resolve(1)
  |> Js.Promise.then_(value => Js.Promise.resolve(value + 1))
  |> Js.Promise.then_(value => Js.Promise.resolve(value));

/* And even better with local open */
let _: Js.Promise.t(unit) =
  Js.Promise.(
    resolve(1)
    |> then_(value => resolve(value + 1))
    |> then_(value => {
         Js.log(value);
         resolve();
       })
  );

/* Waiting for two values */
let _: Js.Promise.t(unit) =
  Js.Promise.(
    all2((resolve(1), resolve("a")))
    |> then_(((v1, v2)) => {
         Js.log("Value 1: " ++ string_of_int(v1));
         Js.log("Value 2: " ++ v2);
         resolve();
       })
  );

/* Waiting for an array of values */
let _: Js.Promise.t(unit) =
  Js.Promise.(
    all([|resolve(1), resolve(2), resolve(3)|])
    |> then_(vs => {
         vs |> Array.iteri((v, i) => Js.log({j|Value $i: $v|j}));
         resolve();
       })
  );