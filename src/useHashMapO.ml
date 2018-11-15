open Belt
module StrHash =
  Id.MakeHashable(struct
                    type t = string
                    let hash (x : t) = String.length x
                    let eq (a : t) (b : t) = a = b
                  end)
let painIndexMap = HashMap.make ~hintSize:10 ~id:(module StrHash)
let () =
  let open HashMap in

    set painIndexMap "western paper wasp" 1.0;
    set painIndexMap "yellowjacket" 2.0;
    set painIndexMap "honey bee" 2.0;
    set painIndexMap "red paper wasp" 3.0;
    set painIndexMap "tarantula hawk" 4.0;
    set painIndexMap "bullet ant" 4.0

let () =
  HashMap.set painIndexMap "bumble bee" 2.0

let () =
  HashMap.forEach painIndexMap
    (fun k  -> fun v  -> Js.log {j|key:$k, val:$v|j})