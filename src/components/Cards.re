module CardsQuery = [%relay.query{|
    query CardsQuery {
      cards {
        edges {
          node {
            text
            name
            image
            manaCost
          }
        }
      }
    }
  |}];



[@react.component]
let make = () => {
    let queryData = CardsQuery.use(~variables=(), ());

    // let item =
    //   switch(edge){
    //     | Some(node) => {ReasonReact.string(node.name)};
    //     | None => React.null;
    //   }

    // let parseData = (~edges=?) =>
    //   switch(edges){
    //     | None => React.null;
    //     | Some(edges) =>
    //       edges->Belt.Array.keepMap(edge =>
    //         switch (edge) {
    //           | Some({node: Some(node)}) => Some(node);
    //           | _ => None;
    //         }
    //     )
    //   }

    switch(queryData.cards.edges) {
      | [||] => <div>{ReasonReact.string("Nada")}</div>
      | edges => 
        edges -> Belt.Array.keepMap(edge =>
        switch(edge){
          | Some({node: Some(node)})  => Some(node);
          | _ => None;
          }
            ) -> Belt.Array.map(item =>
                <div key=item.name>
                  {ReasonReact.string(item.name)}
                </div>
              ) -> React.array;
    }
    
    // let elements = (~edges=?) => 
    //   switch edges {
    //     | None => React.null;
    //     | Some(edges) => 
    //       edges->Belt.Array.map(edge => {
    //         switch(edge) {
    //           | None => React.null;
    //           | Some(edge) =>
    //             switch(edge) {
    //               | Some(node) => <div>{ReasonReact.string("node")}</div>
    //               | None => <div>{ReasonReact.string("no node")}</div>
    //             };
    //           }
    //       })->React.array
    //   };

    // switch(queryData.cards.edges) {
    //   | [||] => <div>{ReasonReact.string("Nada")}</div>
    //   | edges => elements(~edges=edges)
    // }
}


          // {
          //   edges
          //   ->Belt.Array.map(node =>
          //       <li key={node.name}> {React.string(node.text)} </li>
          //     )
          //   /* Since everything is typed, the arrays need to be, too! */
          //   ->React.array
          // }