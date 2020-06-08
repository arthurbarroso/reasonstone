module CardsQuery = [%relay.query{|
    query CardsQuery {
      cards {
        edges {
          node {
            text
            name
          }
        }
      }
    }
  |}];

[@react.component]
let make = () => {
    let queryData = CardsQuery.use(~variables=(), ());

    switch(queryData.cards) {
      | Some(edges) => <div>{ReasonReact.string("Fetched")}</div>
      | None => React.null;
    }
}