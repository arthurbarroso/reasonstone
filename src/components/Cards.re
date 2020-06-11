open Css;
open Utils;
open Webapi.Dom;

let cardsContainerStyle =
  merge([
    style([
      display(flexBox),
      flexDirection(row),
      justifyContent(center),
      flexWrap(wrap),
      listStyle(`none, `inside, `none),
      padding(px(0)),
    ]),
    "cards-container"
  ]);

  
  let outsideContainerStyle =
    merge([
      style([
        display(flexBox),
        flexDirection(column),
      ]),
      "outside-container"
    ]);
    


module CardListFragment = [%relay.fragment
  {|
  fragment Cards_query on Query
    @refetchable(queryName: "CardsRefetchQuery")
    @argumentDefinitions(
      count: { type: "Int!", defaultValue: 40 }
      cursor: { type: "String!", defaultValue: "" }
    ) {
    cards(first: $count, after: $cursor) @connection(key: "Cards_query_cards") {
      edges {
        node {
          id
          image
        }
      }
    }
  }
  |}
];

 type action =
   | Update;

 type state = {
   currentHeight: int
 };


[@react.component]
let make = (~query as queryRef) => {
  let ReasonRelay.{data, hasNext, isLoadingNext, loadNext} = CardListFragment.usePagination(queryRef);
  let cardList = data.cards->CardListFragment.getConnectionNodes_cards;
  // let (height, setHeight) = React.useState(_ => -1000);
  let pageBottom = (e) => scroller(e);
  let handleScroll = (e) => {
     if(pageBottom(e) && !isLoadingNext && hasNext){
       loadNext(~count=15, ()) |> ignore;
     }
   }

   let debounceScroll = Debouncer.make(~wait=5000, handleScroll);

   let bindEvent = () =>
     Document.addEventListener("scroll", debounceScroll, document);

   React.useEffect0(() => {
     bindEvent();

     Some(() => Js.log("Failed binding scroll listener"));
   })


  let dataToShow =
    {cardList
      -> Belt.Array.map(card => 
        <Card image=card.image />)
          } -> React.array;


    <div className=outsideContainerStyle>
      <ul className=cardsContainerStyle>
        dataToShow
      </ul>
      {hasNext ?
        <Button
          text="Load more cards!"
          onClick={_ => loadNext(~count=30, ()) |> ignore} />
        :
        React.null
      }
    </div>
}