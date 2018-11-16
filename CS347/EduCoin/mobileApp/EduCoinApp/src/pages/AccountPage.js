import React from 'react';
import {
  StyleSheet,
  View,
  StatusBar,
  Text
} from 'react-native';
import { List, FlatList, ListItem } from 'react-native-elements'
/*
  This page displays the account balance and transaction history
.*/
const list = [
  {
    name: 'Amy Farha',
    avatar_url: 'https://s3.amazonaws.com/uifaces/faces/twitter/ladylexy/128.jpg',
    subtitle: 'Vice President'
  },
  {
    name: 'Chris Jackson',
    avatar_url: 'https://s3.amazonaws.com/uifaces/faces/twitter/adhamdannaway/128.jpg',
    subtitle: 'Vice Chairman'
  }
]
export default class AccountPage extends React.Component {
    constructor(props) {
    super(props);

    this.state = {
      loading: false,
      data: [],
      page: 1,
      seed: 1,
      error: null,
      refreshing: false
    };
  }
  keyExtractor = (item, index) => index

  renderItem = ({ item }) => (
    <ListItem
      title={item.name}
      subtitle={item.subtitle}
      avatar={{ source: { uri: item.avatar_url } }}
    />
  )


  render () {
    return (
      <FlatList
        keyExtractor={this.keyExtractor}
        data={this.state.dataSource}
        renderItem={this.renderItem}
      />
    )
  }
}

const styles = StyleSheet.create({
  container : {
    backgroundColor: 'rgb(61, 148, 202)',
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
  text : {
    color: '#FFFFFF'
  }
});
