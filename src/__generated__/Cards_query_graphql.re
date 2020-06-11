/* @generated */

module Types = {
  type fragment_cards_edges_node = {
    id: string,
    image: string,
  };
  type fragment_cards_edges = {
    node: option(fragment_cards_edges_node),
    cursor: string,
  };
  type fragment_cards = {edges: array(option(fragment_cards_edges))};

  type fragment = {cards: fragment_cards};
};

module Internal = {
  type fragmentRaw;
  let fragmentConverter: Js.Dict.t(Js.Dict.t(Js.Dict.t(string))) = [%raw
    {json| {"__root":{"cards_edges":{"na":""},"cards_edges_node":{"n":""}}} |json}
  ];
  let fragmentConverterMap = ();
  let convertFragment = v =>
    v
    ->ReasonRelay._convertObj(
        fragmentConverter,
        fragmentConverterMap,
        Js.undefined,
      );
};

type t;
type fragmentRef;
type fragmentRefSelector('a) = {.. "__$fragment_ref__Cards_query": t} as 'a;
external getFragmentRef: fragmentRefSelector('a) => fragmentRef = "%identity";

module Utils = {
  open Types;
  let getConnectionNodes_cards:
    fragment_cards => array(fragment_cards_edges_node) =
    connection =>
      connection.edges
      ->Belt.Array.keepMap(edge =>
          switch (edge) {
          | None => None
          | Some(edge) =>
            switch (edge.node) {
            | None => None
            | Some(node) => Some(node)
            }
          }
        );
};

type operationType = ReasonRelay.fragmentNode;

let node: operationType = [%raw
  {json| (function(){
var v0 = [
  "cards"
];
return {
  "kind": "Fragment",
  "name": "Cards_query",
  "type": "Query",
  "metadata": {
    "connection": [
      {
        "count": "count",
        "cursor": "cursor",
        "direction": "forward",
        "path": (v0/*: any*/)
      }
    ],
    "refetch": {
      "connection": {
        "forward": {
          "count": "count",
          "cursor": "cursor"
        },
        "backward": null,
        "path": (v0/*: any*/)
      },
      "operation": require('./CardsRefetchQuery_graphql.bs.js').node,
      "fragmentPathInResult": []
    }
  },
  "argumentDefinitions": [
    {
      "kind": "LocalArgument",
      "name": "count",
      "type": "Int!",
      "defaultValue": 40
    },
    {
      "kind": "LocalArgument",
      "name": "cursor",
      "type": "String!",
      "defaultValue": ""
    }
  ],
  "selections": [
    {
      "kind": "LinkedField",
      "alias": "cards",
      "name": "__Cards_query_cards_connection",
      "storageKey": null,
      "args": null,
      "concreteType": "CardConnection",
      "plural": false,
      "selections": [
        {
          "kind": "LinkedField",
          "alias": null,
          "name": "edges",
          "storageKey": null,
          "args": null,
          "concreteType": "CardEdge",
          "plural": true,
          "selections": [
            {
              "kind": "LinkedField",
              "alias": null,
              "name": "node",
              "storageKey": null,
              "args": null,
              "concreteType": "Card",
              "plural": false,
              "selections": [
                {
                  "kind": "ScalarField",
                  "alias": null,
                  "name": "id",
                  "args": null,
                  "storageKey": null
                },
                {
                  "kind": "ScalarField",
                  "alias": null,
                  "name": "image",
                  "args": null,
                  "storageKey": null
                },
                {
                  "kind": "ScalarField",
                  "alias": null,
                  "name": "__typename",
                  "args": null,
                  "storageKey": null
                }
              ]
            },
            {
              "kind": "ScalarField",
              "alias": null,
              "name": "cursor",
              "args": null,
              "storageKey": null
            }
          ]
        },
        {
          "kind": "LinkedField",
          "alias": null,
          "name": "pageInfo",
          "storageKey": null,
          "args": null,
          "concreteType": "PageInfoExtended",
          "plural": false,
          "selections": [
            {
              "kind": "ScalarField",
              "alias": null,
              "name": "endCursor",
              "args": null,
              "storageKey": null
            },
            {
              "kind": "ScalarField",
              "alias": null,
              "name": "hasNextPage",
              "args": null,
              "storageKey": null
            }
          ]
        }
      ]
    }
  ]
};
})() |json}
];
