module rec OrderedType: Set.OrderedType with type t = Type.t = {
  type t = Type.t;
  let compare = compare;
}
and Type: {
  type t =
    | A
    | B
    | Union(TypedSet.t);
} = Type
and TypedSet: Set.S with type elt = OrderedType.t = Set.Make(OrderedType);

include Type;

let value = Union(TypedSet.of_list([A, B, A]));