open Css;

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


let cardsContainerStyle =
  merge([
    style([
      display(flexBox),
      flexDirection(row),
      justifyContent(center),
      width(`percent(120.0)),
      flexWrap(wrap),
      listStyle(`none, `inside, `none),
    ]),
    "cards-container"
  ]);

[@react.component]
let make = () => {
  let queryData = CardsQuery.use(~variables=(), ());
  let data =
    switch(queryData.cards.edges) {
      | [||] => <div>{ReasonReact.string("Nada")}</div>
      | edges => 
        edges -> Belt.Array.keepMap(edge =>
        switch(edge){
          | Some({node: Some(node)})  => Some(node);
          | _ => None;
          }
            ) -> Belt.Array.map(item =>
                <li key=item.name>
                  <Card image=item.image />
                </li>
              ) -> React.array;
    };

  <ul className=cardsContainerStyle>
    data
  </ul>
}
